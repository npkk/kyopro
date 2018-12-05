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

template<typename T>
pair<int, vi> bipartite_matching(graph<T> &G, vector<int> U){
    const int INF = numeric_limits<int> :: max() - 5;
    graph<T> H = G;
    H.data.resize(H.size() + 1);
    int NIL = (int)G.size();
    vi ret(H.size(), NIL);
    vi dist(H.size(), -10);

    function<bool(void)> BFS = [&](){
        queue<int> q;
        for(auto&& u:U){
            if(ret[u] == NIL){
                dist[u] = 0;
                q.push(u);
            }else
                dist[u] = INF;
        }
        dist[NIL] = INF;
        while(!q.empty()){
            int u = q.front();q.pop();
            if(dist[u] < dist[NIL])
                for(auto&& e:H.data[u]){
                    if(dist[ret[e.t]] == INF){
                        dist[ret[e.t]] = dist[u] + 1;
                        q.push(ret[e.t]);
                    }
                }
        }
        return dist[NIL] != INF;
    };

    function<bool(int)> DFS = [&](int u){
        if(u != NIL){
            for(auto&& e:H.data[u])
                if(dist[ret[e.t]] == dist[u] + 1)
                    if(DFS(ret[e.t])){
                        ret[e.t] = u;
                        ret[u] = e.t;
                        return true;
                    }
            dist[u] = INF;
            return false;
        } 
        return true;
    };

    int m = 0;
    int c = 0;
    while(BFS()){
        for(auto&& u:U)
            if(ret[u] == NIL)
                if(DFS(u))m++;
    }

    return make_pair(m, ret);
}

//////////////////////////////////////////////////

int main(){
    int x, y, e;
    cin >> x >> y >> e;
    graph<int> g(x+y);
    vi U(x);
    for(int i=0;i<e;i++){
        int f, t;
        cin >> f >> t;
        t += x;
        g.add_edge(f, t, 0);
        g.add_edge(t, f, 0);
    }
    for(int i=0;i<x;i++)U[i] = i;
    pair<int, vi> r = bipartite_matching(g, U);
    cout << r.first << endl;
}
