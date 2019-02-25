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
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

const ll INF = 1LL<<60;
ll n;
ll a[575],b[575];

//区間[l,r)の最小の総和
ll dp[575][575];
bool visited[575][575];

//区間[l,r)の総和
ll get(ll l, ll r){
  ll res = b[r];
  if(l) res -= b[l-1];
  return res;
}

ll dfs(ll l, ll r){
  if(l == r) return 0;
  if(visited[l][r]) return dp[l][r];

  visited[l][r] = true;
  ll res = INF;
  //分裂させて和を足す
  FOR(i, l, r) {
    res = min(res, dfs(l, i)+dfs(i+1, r)+get(l, r));
    //res %= MOD;
  }
  return dp[l][r] = res;
}

int
main(void){  

  cin >> n;
  REP(i,n) cin >> a[i];

  int l=0, r=n;
  REP(i, n) REP(j, n) dp[i][j] = INF;
  
  b[0] = a[0];
  FOR(i,1,n) b[i] = b[i-1]+a[i];

  cout << dfs(0, n-1) << endl;
  
  return 0;
}
