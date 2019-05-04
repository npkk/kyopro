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

#define N 6

int main(){
    int T, W;
    cin >> T >> W;
    for(int C = 1; C <= T; ++C){
        float m[N][N + 1] = {
            {2, 1, 1, 1, 1, 1, 0},
            {4, 2, 1, 1, 1, 1, 0},
            {8, 2, 2, 1, 1, 1, 0},
            {16, 4, 2, 2, 1, 1, 0},
            {32, 4, 2, 2, 2, 1, 0},
            {64, 8, 4, 2, 2, 2, 0},
        };
        int b[N];
        for(int i=1;i<=6;i++){
            cout << i << endl << flush;
            cin >> m[i][N];
        }

        for (int k = 0; k < N; k++) {
            // ピボット係数
            float p = m[k][k];

            // ピボット行を p で除算
            for (int j = k; j < N + 1; j++){
                m[k][j] /= p;
                cerr << m[k][j] << " ";
            }
            cerr << endl;

            // ピボット列の掃き出し
            for (int i = 0; i < N; i++) {
                if (i != k) {
                    float d = m[i][k];
                    for (int j = k; j < N + 1; j++)
                        m[i][j] -= d * m[k][j];
                }
            }
        }
        for(int i=0; i<N;i++){
            for(int j=0;j<N+1;j++)cerr << m[i][j] << " ";
            cerr << endl;
        }
        for(int i=0; i<5;i++)cout << m[i][N] << " ";
        cout << m[5][N] << endl;
        cout << flush;
        int ret;
        cin >> ret;
    }
    return 0;
}
