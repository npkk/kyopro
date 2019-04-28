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
    vl a(n);
    for(auto&& x:a)cin >> x;
    i64 ret = 0;
    int nval = 0;
    vl b(n);
    for(int i=0;i<n;i++){
        b[i] = max(a[i], -a[i]);
        ret += b[i];
        if(a[i] < 0) nval++;
    }
    sort(b.begin(), b.end());
    cerr << nval << " " << ret << endl;
    if(nval & 1){
        cout << ret - 2 * b[0] << endl;
    }else{
        cout << ret << endl;
    }
    return 0;
}
