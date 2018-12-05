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

///////////////////////////////////////////////////////

struct unionfind{
    vi data;
    unionfind(int n):data(n, -1){};
    int root(int idx){
        return data[idx] < 0 ? idx : data[idx] = root(data[idx]);
    }
    bool same(int l, int r){
        return (l = root(l))==(r = root(r));
    }
    void join(int l, int r){
        l = root(l); r = root(r);
        if(l != r){
            if(data[l] > data[r])swap(l, r);
            data[l] += data[r];
            data[r] = l;
        }
    }
    int size(int idx){
        return -data[root(idx)];
    }
};

//////////////////////////////////////////////////

int main(){
    return 0;
}