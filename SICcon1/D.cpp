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

ll nl, nm;
ll a[575777];

map<ll,ll> mp;
vector<set<ll>> vs;

int
main(void){  
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  REP(i, m) cin >> a[i];

  ll r = 0LL, minlen = 1e8+1;
  ll sum = 0LL;
  REP(l, m){    
    while(r < m && sum < n){
      sum += a[r];
      r++;
    }
    //check
    //cout << "l: " << l << " r: " << r << " sum: " << sum << endl;
    //if(sum >= n){
    //}
    if(minlen > r-l+1){
      minlen = r-l+1;
      vs.clear();
      FOR(i, l, r+1){
	mp[i]++;
      }
    }    
    if(l == r) r++;
    else sum -= a[l];
  }

  for(auto itr=vs.begin(); itr!=vs.end(); itr++){
    (*itr)
  }
  
  //積集合の中で重なるもの
  /*
  bool f = false;
  for(auto itr=mp.begin(); itr!=mp.end(); itr++){
    cout << itr->second << endl;
    f = true;
    break;
  }
  if(!f) cout << "0" << endl;
  */
  
  return 0;
}
