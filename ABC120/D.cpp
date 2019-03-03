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

template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

const int MAX = 51;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}


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
    if(d[y] < d[x]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  int size(T x){ return -d[find(x)];}
  bool same(T x, T y){
    return find(x) == find(y);
  }
};


P ab[100010];

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n, m;
  cin >> n >> m;
  
  REP(i, m){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    ab[i].first = a;
    ab[i].second = b;
  }
  vector<ll> v;
  UnionFind<int> uf = UnionFind<int>(n+1);
  ll ans = 0;

  
  COMinit();
  ans = COM(n,2);
  

  //ans = n*(n-1)/2;
  v.push_back(ans);
  
  ROF(i, m-1, 0){
    ll x , y;    
    x = ab[i].first, y = ab[i].second;
    ll size_x = uf.size(x), size_y = uf.size(y);
    if(uf.unite(x,y)){

      ans -= size_x*size_y;
    }
    ans = max(0LL, ans);
    v.push_back(ans);
  }
  
  reverse(v.begin(), v.end());

  int i=0;
  for(auto &e: v) {
    if(i > 0)
      cout << e << endl;
    i++;
  } 
  return 0;
}
