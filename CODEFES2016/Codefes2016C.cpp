//$g++ -std=c++11 Template.cpp 

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

priority_queue<int> q_descending;
priority_queue<int, vector<int>, greater<int> > q_ascending;

/*
  UnionFind<int> uf = UnionFind<int>(n+1); //nだとREでるの謎い..
  REP(i, m) uf.unite(x[i], y[i]);
*/
template <typename T>
class UnionFind {
public:
  T n;
  vector <T> d;
  UnionFind(T n) :d(n, -1) {} 
  int find(T x){
    if(d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(T x, T y){
    x = find(x);
    y = find(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  int size(T x){ return -d[find(x)];}
  bool same(T x, T y){
    return find(x) == find(y);
  }
};


int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  UnionFind<int> uf = UnionFind<int>(n+m); //nだとRE
  
  for(int i=0, k; i<n; ++i){
    cin >> k;
    for(int j=0, l; j<k; ++j){
      cin >> l;
      //lだとかぶるからダメ , 言葉と人は違うものなので分ける
      uf.unite(i, n+l-1);
      //uf.unite(i, n+l-1);
      //cout << n+l-1 << endl;
    }
  }

  //REP(i, n+m) cout << uf.find(i) << endl;
  
  for(int i=1; i< n; i++){
    if(!uf.same(i-1, i)) {cout << "NO" << endl; return 0;}
  }

  cout << "YES" << endl;
  
  return 0;
}
