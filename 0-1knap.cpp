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

//0-1 knapsack


int n;
const int MAX_N = 41;
const int INF = 1e5;
ll w[MAX_N], v[MAX_N];
ll W;
pair<ll, ll> ps[1 << (MAX_N/2)];

void solve(){
  int n2 = n/2;
  REP(i, (1<<n2)){
    ll sw = 0, sv = 0;
    REP(j, n2){
      if(i & 1<<j){
	sw += w[j];
	sv += v[j];
      }
    }
    ps[i] = make_pair(sw, sv);
  }

  sort(ps, ps+(1<<n2));
  int m=1;
  for(int i=1; i< 1<<n2; i++){
    if(ps[m-1].second < ps[i].second) ps[m++] = ps[i];
  }

  ll res = 0;
  REP(i, 1<<(n-n2)){
    ll sw = 0, sv = 0;
    REP(j, (n-n2)){
      if(i & 1<<j){
	sw += w[n2+j];
	sv += v[n2+j];
      }
    }
    if(sw <= W){
      //cerr << (lower_bound(ps, ps+m, make_pair(W-sw, (ll)INF)) -1 )->second << endl;
      //REP(k, m) cerr << ps[k].first << " " << ps[k].second << endl;
      //cerr << (lower_bound(ps, ps+m, make_pair(W-sw, (ll)INF)) -1 ) << endl;      
      ll tv = (lower_bound(ps, ps+m, make_pair(W-sw, (ll)INF)) -1 )->second;
      res = max(res, sv+tv);
    }
  }
  cout << res << endl;
}

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  REP(i,n) cin >> w[i];
  REP(i,n) cin >> v[i];
  cin >> W;
    
  solve();
  
  /*
  int a[5] = {0, 1, 2, 3, 4};
  cout << (lower_bound(a, a+n, 2))->second << endl;
  */
  
  return 0;
}
