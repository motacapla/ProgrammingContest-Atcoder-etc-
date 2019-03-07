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

/*
vector<pair<ll,ll> > G[MAXN];
G[from].push_back(pair<ll,ll>(to, cost));
for(ll i = 0; i < V; ++i) {
    for(ll j = 0; j < (ll)G[i].size(); ++j) {
        // from `i` to `G[i][j].first` cost `G[i][j].second`
    }
}
 */
//https://www.qoosky.io/techs/5cd1a59497

const int INF = 1e8;
const int MAX_N = 1e8;
vector<pair<ll,ll> > G[MAX_N];
ll dist[MAX_N];
ll n,m;

/*
void bellman_ford(ll all, ll start){
  memset(dist, INF*INF, sizeof(dist));
  dist[0] = 0;
  REP(i, 5) cout << dist[i] << endl;
}
*/

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;  
  
  REP(i, m){
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--; c*=-1;
    G[a].push_back(make_pair(b, c));
  }

  bellman_ford(n, 0);
  
  return 0;
}
