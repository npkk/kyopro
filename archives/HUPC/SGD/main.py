import numpy as np
import time
import sys

class term():
    def __init__(self, d, c, v):
        self.d = d
        self.c = c
        self.v = np.array(v)
        assert(self.d == len(v))

class f():
    def __init__(self, test=False):
        val = list(map(int, input().split()))
        self.N = val[0]
        self.K = val[1]
        self.terms = []
        self.test = test
        self.C = 0
        for i in range(self.K):
            val = list(map(int, input().split()))
            if(val[0] == 0):
                self.C = val[1]
            self.terms.append(term(val[0], val[1], val[2:]))

    def forward(self,x):
        assert(x.shape[0] == self.N)
        ret = 0
        for t in self.terms:
            tret = t.c
            for v in t.v:
                tret *= x[v-1]
            if self.test:
                print('{} {} {} {}'.format(t.d, t.c, t.v, tret), file=sys.stderr)
            ret += tret
        return ret

class g():
    def __init__(self, S, H, debug=False):
        self.S = S
        self.H = H
        self.A = 0 * np.ones((S, S), dtype=float)
        self.A -= (np.diag(np.diag(self.A)))
        self.B = 0 * np.ones((S, 1), dtype=float)
        self.dAs = np.zeros_like(self.A)
        self.dBs = np.zeros_like(self.B)
        # self.LF = loss_function
        self.Ls = 0
        self.bn = 0
        self.debug = debug

    def forward(self, y, FX):
        assert(x.shape[0] == self.S)
        assert(x.shape[1] == 1)
        ty = np.transpose(y)
        dA = np.triu(np.dot(y, ty), k=1)
        dB = y
        GY = np.squeeze(self.H + np.dot(np.dot(ty, self.A), y) + np.dot(np.transpose(self.B), y))
        L = GY - FX
        # print(type(L))
        # if self.debug:
            # print('L:{:.2f}'.format(L[0]))
        self.Ls += L        
        if L < 0:
            L *= 3
        self.dAs += L * dA
        self.dBs += L * dB
        self.bn += 1
        return L

    def update(self, lr):
        self.A -= lr / self.bn * self.dAs 
        self.B -= lr / self.bn * self.dBs
        self.H -= lr / self.bn 
        self.dAs = np.zeros_like(self.A)
        self.dBs = np.zeros_like(self.B)
        self.Ls = 0
        self.bn = 0

    def ceil(self):
        self.A = np.ceil(self.A) 
        self.B = np.ceil(self.B) 
        self.H = np.ceil(self.H)

# constants
Batch = 128
LR = 0.001

T1 = time.time()
F = f(False)
G = g(F.N + 1, F.C, True)

T2 = time.time()

x2 = np.ones((G.S, 1), dtype=float)
while T2 - T1 < 29:
    for count in range(Batch):
        x = np.random.randint(2, size=G.S)
        x = np.expand_dims(x, axis=1)
        L = G.forward(x, F.forward(x[0:F.N]))
        _ = G.forward(x2, F.forward(x2[0:F.N]))
    G.update(LR)
    T2 = time.time()
    # print(T2-T1, file=sys.stderr)
G.ceil()
# print(G.A, file=sys.stderr)
# print(G.B, file=sys.stderr)
# print(G.H, file=sys.stderr)

L = 0
L += len(np.argwhere(G.A != 0))
L += len(np.argwhere(G.B != 0))
L += len(np.argwhere(G.H != 0))
print('{} {}'.format(G.S, L))
if(G.H!= 0):
    print('0 {:d}'.format(int(G.H)))
for i in range(G.S):
    for j in range(i+1, G.S):
        if(int(G.A[i][j]) != 0):
            print('2 {:d} {:d} {:d}'.format(int(G.A[i][j]), i+1, j+1))
for i in range(G.S):
    if(int(G.B[i]) != 0):
        print('1 {:d} {:d}'.format(int(G.B[i]), i+1))
# print(time.time() - T1, file=sys.stderr)