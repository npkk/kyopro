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
    int n;
    cin >> n;
    vi c(n);
    vi v(n);
    for(auto && x:v)cin >> x;
    for(auto && x:c) cin >> x;
    int ret = 0;
    for(int i=0;i<n;i++){
        ret += max(v[i] - c[i], 0);
    }
    cout << ret << endl;
    return 0;
}
