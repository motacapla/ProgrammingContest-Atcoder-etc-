//#include <bits/stdc++.h>
#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <iomanip>
#include <iostream>
#include <fstream>

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define ROF(i, j, k) for(int i = (int)(j); i >= (int)(k); --i)
#define FORLL(i, n, m) for(long long i = n; i < (long long)(m); i++)
#define SORT(v, n) sort(v, v+n)
#define REVERSE(v) reverse((v).begin(), (v).end())

using namespace std;
using ll = long long;
const ll MOD=1000000007LL;
typedef pair<int, int> P;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

//x, y, idx
typedef std::tuple<double, double, int> mytuple;
//https://minus9d.hatenablog.com/entry/2014/07/05/215756
bool mycompare( const mytuple &lhs, const mytuple &rhs )
{
    if (std::get<0>(lhs) != std::get<0>(rhs)) return std::get<0>(lhs) < std::get<0>(rhs);
    if (std::get<1>(lhs) != std::get<1>(rhs)) return std::get<1>(lhs) < std::get<1>(rhs);
    return std::get<2>(lhs) < std::get<2>(rhs);
}
vector<mytuple> v;

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  
  REP(i, n){
    double x, y;
    cin >> x >> y;
    mytuple t = make_tuple(x, y, i);
    v.push_back(t);
  }
  sort(v.begin(), v.end(), mycompare);

  const string filename_o = "output.txt";
  ofstream ofs(filename_o);
  
  for(auto& element: v){
    //cout << get<0>(element) << " " << get<1>(element) << " " << get<2>(element) << endl;
    cout << get<2>(element) << endl;
    //ofs << get<2>(element) << endl;    
  }

  ofs.close();
  
  return 0;
}
