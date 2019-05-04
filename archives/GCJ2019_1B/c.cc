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

template <typename T>
class segtree_max
{
  public:
    vector<T> data;
    int size;
    segtree_max<T>(int size_) : size(1)
    {
        while (size < size_)
            size <<= 1;
        data.assign(size * 2, 0);
    }
    segtree_max<T>(vector<T> &src) : size(1)
    {
        while (size < src.size())
            size <<= 1;
        data.assign(size * 2, 0);
        for (int i = 0; i < src.size(); i++)
        {
            update(i, src[i]);
        }
    };
    void update(int idx, int v)
    {
        int f = idx + size - 1;
        data[f] = v;
        while (f)
        {
            --f /= 2;
            data[f] = max(data[2 * f + 1], data[2 * f + 2]);
        }
    }
    T rmax(int l, int r)
    { //return max[l,r)
        int f = l + size - 1;
        int k = 1;
        while (f % 2 && l + k * 2 <= r)
        {
            f /= 2;
            k *= 2;
        }
        if (l + k > r)
            return 0;
        else if (l + k == r)
            return data[f];
        else
            return max(data[f] ,rmax(l + k, r));
    }
};


int main(){
    int T;
    cin >> T;
    for(int cases = 1; cases <= T; cases++){
        int n, k;
        cin >> n >> k;
        vector<int> c(n), d(n);
        for(auto&& x:c)cin >> x;
        for(auto&& x:d)cin >> x;
        segtree_max<int> mc(c);
        segtree_max<int> md(d);
        int ret = 0;
        for(int L=0;L<n;L++){
            int f = abs(mc.rmax(L, L+1) - md.rmax(L, L+1));
            if(f <= k) ret++;
            for(int R=L+1, h = f;R<n;R++){
                int g = abs(mc.rmax(L, R+1) - md.rmax(L, R+1));
                if(g <= k)ret++;
                if(g > h && g > k)break;
                h = g;
            }
        }
        cout << "Case #" << cases << ": " << ret << endl;
    }
    return 0;
}
