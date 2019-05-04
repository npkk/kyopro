#include <iostream>
#include <cstdio>
#include <sstream>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>

#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#include <chrono>
#include <random>

using namespace std;
using i64 = int_fast64_t;
using ui64 = uint_fast64_t;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<i64>;
using vvl = vector<vl>;
using vd = vector<double>;
using vvd = vector<vd>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

//////////////////////////////////////////////////

int main(){
    int T;
    cin >> T;
    for(int cases=1;cases<=T;cases++){
        int p, q;
        cin >> p >> q;
        vector<int> vx(q+2, 0), vy(q+2, 0);
        // int minx = 0, maxx = q, miny = 0, maxy = q;
        for(int i=0;i<p;i++){
            int x, y;
            char d;
            cin >> x >> y >> d;
            switch(d){
                case 'N':
                // miny = max(miny, y + 1);
                vy[y+1] += 1;
                vy[q+1] -= 1;
                break;
                case 'S':
                // maxy = min(maxy, y - 1);
                vy[0] += 1;
                vy[y] -= 1;
                break;
                case 'W':
                // maxx = min(maxx, x - 1);
                vx[0] += 1;
                vx[x] -= 1;
                break;
                case 'E':
                vx[x+1] += 1;
                vx[q+1] -= 1;
                // minx = max(minx, x + 1);
                break;
            }
        }
        for(int i=0;i<=q;i++){
            vx[i+1] += vx[i];
            vy[i+1] += vy[i];
        }
        // for(auto&& x:vx)cerr << x << " ";
        // cerr << endl;
        // for(auto&& x:vy)cerr << x << " ";
        // cerr << endl;
        int mx = 0, ax = 0, my = 0, ay = 0;
        for(int i=0;i<=q;i++){
            if(vx[i] > mx){
                mx = vx[i];
                ax = i;
            }
            if(vy[i] > my){
                my = vy[i];
                ay = i;
            }
        }
        cout << "Case #" << cases << ": " << ax << " " << ay << endl;
    }
    return 0;
}
