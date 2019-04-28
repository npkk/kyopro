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
    vector< vector< edge<T> > > data;
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
vi scc_tarjan(graph<T> &g){
    vi index(g.size(), -1);
    vi lowlink(g.size(), -1);
    vi scc(g.size(), -1);
    stack<int> s;
    vb ons(g.size(), false);
    int dfs_index = 0, scc_index = 0;
    
    function<void(int)> sc = [&](int v){
        index[v] = dfs_index;
        lowlink[v] = dfs_index;
        dfs_index++;
        s.push(v);
        ons[v] = true;
        for(int i=0;i<g.data[v].size();i++){
            int w = g.data[v][i].t;
            if(index[w] < 0){
                sc(w);
                lowlink[v] = min(lowlink[v], lowlink[w]);
            }else if(ons[w]){
                lowlink[v] = min(lowlink[v], index[w]);
            }
        }
        if(lowlink[v] == index[v]){
            int w;
            do{
                w = s.top();
                s.pop();
                ons[w] = false;
                scc[w] = scc_index;
            }while(w != v);
            scc_index++;
        }
    };
    for(int i=0;i<g.size();i++)
        if(index[i] < 0)sc(i);
    return scc;
};

//////////////////////////////////////////////////

// verify GRL_3_C 0.12s
int main(){
    int V, E;
    cin >> V >> E;
    graph<int> g(V);
    for(int i=0;i<E;i++){
        int s, t;
        cin >> s >> t;
        g.add_edge(s, t, 0);
    }
    vi ret = scc_tarjan(g);
    int Q;cin >> Q;
    for(int i=0;i<Q;i++){
        int u, v;
        cin >> u >> v;
        cout << (ret[u] == ret[v]) << endl;
    }
    return 0;
}