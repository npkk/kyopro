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

///////////////////////////////////////////////////////

template<typename T>
struct edge{
    int f, t;
    T data;
    edge(int f_, int t_, T data_):f(f_), t(t_), data(data_){};
    edge(){};
    bool operator<(const edge& r){
        return this->data < r.data;
    }
};

template<typename T>
struct graph{
    vector< vector<edge<T> > > data;
    graph(int n):data(n){};
    graph(){};
    int size(){
        return (int)data.size();
    }
    void add_edge(int f, int t, T c){
        data[f].emplace_back(f, t, c);
    }
};

//////////////////////////////////////////////////

int main(){
    return 0;
}