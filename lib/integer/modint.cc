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

template<class T>
istream& operator >> (istream& is, T& vec){
    for(auto&& x:vec) is >> x;
    return is;
}

template<class T>
auto operator<<(std::ostream& os, const T& vec)
    -> typename std::conditional<true, std::ostream&, decltype(*vec.begin())>::type{
    os << "[ ";
    for(auto it = vec.begin(); it != vec.end(); ++it){
        os << *it << (it+1 == vec.end() ? " " : ", ");
    }
    os << "]";
    return os;
}

//////////////////////////////////////////////////

struct modint{
    int value, mod;
    modint(int value_, int mod_):value(value_), mod(mod_){value = value % mod;};
    modint(int mod_):value(0LL), mod(mod_){};
    
    modint& operator= (int val){ value = val % mod; return *this;}
    modint operator+ (int val){ return modint(value + val, mod);}
    modint operator- (int val){ return modint(mod + value - val, mod);}
    modint operator* (int val){ return modint(value * val, mod);}
    modint& operator+= (int val){ value = (value + val) % mod; return *this;}
    modint& operator-= (int val){ value = (mod + value - val) % mod; return *this;}
    modint& operator*= (int val){ value = (value * val) % mod; return *this;}

    operator int(){return value;}
    friend ostream& operator << (ostream& os, const modint &x){ os << x.value; return os;}
};

struct modi64{
    i64 value, mod;
    modi64(i64 value_, i64 mod_):value(value_), mod(mod_){value = value % mod;};
    modi64(i64 mod_):value(0LL), mod(mod_){};
    
    modi64& operator= (i64 val){ value = val % mod; return *this;}
    modi64 operator+ (i64 val){ return modi64(value + val, mod);}
    modi64 operator- (i64 val){ return modi64(mod + value - val, mod);}
    modi64 operator* (i64 val){ return modi64(value * val, mod);}
    modi64& operator+= (i64 val){ value = (value + val) % mod; return *this;}
    modi64& operator-= (i64 val){ value = (mod + value - val) % mod; return *this;}
    modi64& operator*= (i64 val){ value = (value * val) % mod; return *this;}
    modi64 operator/ (i64 val){ return modi64(value * modi64(val, mod).pow(mod-2LL).value , mod);}
    modi64 operator/= (i64 val){ 
        value = (value * modi64(val, mod).pow(mod-2LL).value) % mod; 
        return *this;
    }
    modi64 pow(i64 r){
        modi64 ret(1LL, mod);
        modi64 a(value, mod);
        while(r){
            if(r&1LL)ret *= a;
            a *= a;
            r >>= 1;
        }
        return ret;
    }
    operator i64(){return value;}
    friend ostream& operator << (ostream& os, const modi64 &x){ os << x.value; return os;}
};



int main(){
    const i64 M = 1e9+7LL;
    i64 h, w, a, b;
    cin >> h >> w >> a >> b;
    vector<modi64> facts(300000, modi64(1LL , M));
    for(i64 i=2;i<300000;i++){
        facts[i] = facts[i-1] * i;
    }
    function<modi64(i64, i64)> C = [&](i64 n, i64 r){
        return (facts[n] / (facts[r] * facts[n-r]));
    };
    modi64 ret = C(h+w, w);
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            // TODO: verify implementation ABC058_b
        }
    }

    return 0;
}
