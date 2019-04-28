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

i64 gcd(i64 a, i64 b){
    while(b){
        i64 t = b;
        b = a % b;
        a = t;
    }
    return a;
}


int main(){
    i64 n;
    cin >> n;
    deque<i64> a(n);
    for(auto&& x:a) cin >> x;
    sort(a.begin(), a.end(), greater<i64>());
    
    i64 ret2 = a[1];
    for(int i=1; i<n;i++)ret2 = gcd(ret2, a[i]);
    
    i64 ret1 = a[0];
    a.pop_front();
    while(a.size() > 1){
        sort(a.begin(), a.end(),
            [&](const i64 &l, const i64 &r){
            return gcd(ret1, l) > gcd(ret1, r);
        });
        while(gcd(ret1, a[0]) > gcd(ret1, a[1]) && a.size() > 1){
            ret1 = gcd(ret1, a[0]);
            a.pop_front();
        }
    }
    cout << max(ret1, ret2) << endl;
}
