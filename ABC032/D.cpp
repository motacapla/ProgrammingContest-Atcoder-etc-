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

//解説AC
//https://atcoder.jp/contests/abc032/submissions/4835097

int
main(void){  
  ios_base::sync_with_stdio(false);

  ll n, w;
  cin >> n >> w;
  vector<ll> V(n), W(n);
  REP(i,n) cin >> V[i] >> W[i];
  ll wval = *max_element(W.begin(), W.end());
  ll vval = *max_element(V.begin(), V.end());
  
  if(n <= 200 && wval <= 1001){
    vector<ll> dp(wval * n + 10);
    REP(i, n) ROF(j, w, 0){
      if(j+W[i] <= w) dp[j+W[i]] = max(dp[j+W[i]], dp[j]+V[i]);
    }
    cout << dp[w] << endl;
  }
  else if(n <= 200 && vval <= 1001){
    //cerr << "hoge" << endl;
    ll zmz = vval * n + 4;
    vector<ll> dp(zmz+3, 1LL<<60);
    dp[0] = 0;
    REP(i, n) ROF(j, zmz, 0){
      if(j+V[i] <= zmz) dp[j+V[i]] = min(dp[j+V[i]], dp[j]+W[i]);  
    }
    ll ans = 0;
    REP(i, zmz) if(dp[i] <= w) ans = i;
    cout << ans << endl;    
  }
  else{
    //半分全列挙
    ll ans = 0;
    map<ll, ll> mp;
    int nn = n/2, rest_n = n - nn;
    REP(i, 1<<nn){
      ll wtmp = 0, vtmp = 0;
      REP(j, nn) if(i & (1<<j)){
	wtmp += W[j], vtmp += V[j];
      }
      if(wtmp <= w) mp[wtmp] = max(mp[wtmp], vtmp);
    }    
    ll old = 0;
    //容量に対して最適なアイテムを入れる
    for(auto &e: mp){
      if(e.second < old) e.second = old;
      old = e.second;
    }
    mp[1LL<<60] = 0;
    REP(i, 1<<rest_n){
      ll wtmp = 0, vtmp = 0;
      REP(j, rest_n) if(i & 1<<j){
	wtmp += W[j+nn];
	vtmp += V[j+nn];
      }
    
      ll tgt = w - wtmp;
      if(tgt < 0) continue;
      auto it = mp.lower_bound(tgt);
      if(it->first > tgt) it--;
      ans = max(ans, vtmp + it->second);
    }
    cout << ans << endl;
  }
  return 0;
}
