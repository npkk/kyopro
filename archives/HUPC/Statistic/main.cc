#include <cstdio>
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;

struct term{
    int d_, c_;
    vector<int> v_;
    term(int d, int c, vector<int> v):d_(d), c_(c), v_(v){
        assert(d == (int)v.size());
    }
};

struct HUPC{
    int N_, K_;
    vector<term> terms_;
    HUPC(){}
    HUPC(const HUPC &ref){
        this -> N_ = ref.N_;
        this -> K_ = ref.K_;
        this -> terms_ = ref.terms_;        
    }
    void init(){
        cin >> N_ >> K_;
        for(int i=0;i<K_;i++){
            int d, c; vector<int> v;
            cin >> d >> c;
            v.resize(d);
            for(auto&& x:v) cin >> x;
            terms_.emplace_back(d, c, v);
        }
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    HUPC F;
    F.init();
    HUPC G = F;

    sort(G.terms_.begin(), G.terms_.end(), [&](const term &l, const term &r){
        return l.d_ < r.d_;
    });

    
}