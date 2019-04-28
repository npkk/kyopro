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

// template<class T>
// istream& operator >> (istream& is, T& vec){
//     for(auto&& x:vec) is >> x;
//     return is;
// }

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

int mergecount(vector<int> &a) {
  int count = 0;
  int n = a.size();
  if (n > 1) {
    vector<int> b(a.begin(), a.begin() + n/2);
    vector<int> c(a.begin() + n/2, a.end());
    count += mergecount(b);
    count += mergecount(c);
    for (int i = 0, j = 0, k = 0; i < n; ++i)
      if (k == c.size())       a[i] = b[j++];
      else if (j == b.size())  a[i] = c[k++];
      else if (b[j] <= c[k])   a[i] = b[j++];
      else                   { a[i] = c[k++]; count += n/2 - j; }
  }
  return count;
}

int main(){
    string s;
    cin >> s;
    i64 res = 0;
    vector<int> a(s.length());
    for(int i=0;i<s.length();i++){
        a[i] = (s[i] == 'B');
    }
    deque<int> b(a.begin(), a.end());
    b.push_front(0);
    for(int i=0;i<s.length();i++){
        b[i+1] += b[i];
    }
    cerr << a << endl;
    cerr << b << endl;
    for(int i=0;i<s.length();i++){
        if(!a[i])res += (i64)b[i+1];
    }
    cout << res << endl;
}
