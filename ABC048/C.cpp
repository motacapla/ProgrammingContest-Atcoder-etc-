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

int a[575777], aa[575777];

int
main(void){  
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, x;
  cin >> n >> x;
  REP(i, n) cin >> a[i];

  REP(i, n) aa[i] = a[i];
  
  ll ans = 0LL;

  //n: odd
  for(int i=1; i<n; i+=2){
    int left = a[i-1]+a[i];
    if(left > x) {
      ans += left-x;
      a[i] -= left-x;
    }
    int right = a[i]+a[i+1];
    if(right > x) {
      ans += right-x;
      a[i] -= right-x;		  
    }
  }
  //n: even
  if(n%2 == 0){
    ll a2=0LL;
    for(int i=0; i<n; i+=2){
      if(i > 0){
	int left = a[i-1]+aa[i];      
	if(left > x) {
	  a2 += left-x;
	  aa[i] -= left-x;
	}
      }
      int right = a[i] + aa[i+1];
      if(right > x) {
	a2 += right-x;
	aa[i] -= right-x;	
      }
    }    
    ans = min(ans, a2);
  }

  cout << ans << endl;
  
  return 0;
}

