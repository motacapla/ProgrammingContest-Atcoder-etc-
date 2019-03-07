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

//wfで INFにするの 忘れない 対角ゼロも　忘れないでね


const ll INF = 1e18;
const int MAX_N = 1e4;

ll g[MAX_N][MAX_N];
ll dist[MAX_N];
int N,M,R;

void wf(){
  REP(k, N){
    REP(i, N){
      REP(j, N){
	g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
      }
    }
  }
}

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M >> R;
  vector<ll> r(R);
  REP(i,R) cin >> r[i], r[i]--;
  sort(r.begin(), r.end());

  REP(i, N) REP(j, N) g[i][j] = INF;
  REP(i, N) g[i][i] = 0;
  
  REP(i,M){
    ll a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    g[a][b] = c;
    g[b][a] = c;
  }
  
  wf();
  
  ll ans = INF; 
  while(next_permutation(r.begin(), r.end())){
    ll res = 0;
    REP(i, R-1) res += g[r[i]][r[i+1]];
    ans = min(ans, res);
  }
  cout << ans << endl;
  return 0;
}
