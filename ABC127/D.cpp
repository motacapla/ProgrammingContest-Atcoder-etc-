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
#include <stack>
#include <bitset>

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

//ll a[1000100];
pair<ll, ll> cb[1000100];
vector<pair<ll, ll>> ans;

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n, m;
  cin >> n >> m;
  REP(i,n) {
    ll x; cin >> x;
    ans.push_back({x, 1});
  }
  
  REP(i,m) {
    ll b, c;
    cin >> b >> c;
    //cin >> cb[i].first >> cb[i].second;
    ans.push_back({c, b});
  }  
  //sort(cb, cb+m);
  /*
  REP(i, n) cerr << ans[i].first << " ";
  cerr << endl;
  */
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  /*
  for(auto &e: ans) cerr << e.first << " ";
  cerr << endl;  
  */
  ll rest = n;
  ll sum = 0LL;
  for(int i=0; i<n; i++) {
    //cerr << ans[i].first << " " << ans[i].second << endl;
    if(rest < ans[i].second){
      sum += ans[i].first*rest;      
      break;
    }
    else{
      sum += ans[i].first*ans[i].second;
      rest -= ans[i].second;
    }
  }
  cout << sum << endl;
  
  return 0;
}
