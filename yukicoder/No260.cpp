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


//i桁目, smaller, 3がつく, mod 3, mod 8
ll dp[20005][2][2][3][8];

ll calc(string s, bool f){
  ll n = s.size();
  REP(i, n+1) REP(j, 2) REP(k, 2) REP(l, 3) REP(m, 8) dp[i][j][k][l][m] = 0;
  
  dp[0][0][0][0][0] = 1;
  REP(i, n) {
    REP(j, 2){
      REP(k, 2){
	REP(l, 3){
	  REP(m, 8){
	    ll lim = (j ? 9 : s[i]-'0');	    
	    REP(d, lim+1) (dp[i+1][j||d<lim][k|(d == 3)][(l*10+d)%3][(m*10+d)%8] += dp[i][j][k][l][m]) %= MOD;    
	  }
	}
      }
    }  
  }
  ll ans = 0LL;
  REP(j, 2) REP(k, 2) REP(l, 3) REP(m, 8) {
    if((k||!l)&& m) (ans+=dp[n][j][k][l][m])%=MOD;    
  }
  return ans;
}
//cout << (MOD + calc(b) - calc(a)) % MOD << endl;

int
main(void){  
  cin.tie(0);
  ios::sync_with_stdio(false);

  string a, b, s;
  cin >> a >> b;

  s = b;
  ll n = s.size();
  REP(i, n+1) REP(j, 2) REP(k, 2) REP(l, 3) REP(m, 8) dp[i][j][k][l][m] = 0;
  
  dp[0][0][0][0][0] = 1;
  REP(i, n) {
    REP(j, 2){
      REP(k, 2){
	REP(l, 3){
	  REP(m, 8){
	    ll lim = (j ? 9 : s[i]-'0');	    
	    REP(d, lim+1) (dp[i+1][j||d<lim][k|(d == 3)][(l*10+d)%3][(m*10+d)%8] += dp[i][j][k][l][m]) %= MOD;    
	  }
	}
      }
    }  
  }
  ll ans = 0LL;
  REP(j, 2) REP(k, 2) REP(l, 3) REP(m, 8) {
    if((k||!l)&& m) (ans+=dp[n][j][k][l][m])%=MOD;    
  }  

  s = a;
  n = s.size();
  REP(i, n+1) REP(j, 2) REP(k, 2) REP(l, 3) REP(m, 8) dp[i][j][k][l][m] = 0;
  
  dp[0][0][0][0][0] = 1;
  REP(i, n) {
    REP(j, 2){
      REP(k, 2){
	REP(l, 3){
	  REP(m, 8){
	    ll lim = (j ? 9 : s[i]-'0');	    
	    REP(d, lim+1) (dp[i+1][j||d<lim][k|(d == 3)][(l*10+d)%3][(m*10+d)%8] += dp[i][j][k][l][m]) %= MOD;    
	  }
	}
      }
    }  
  }
  REP(j, 2) REP(k, 2) REP(l, 3) REP(m, 8) {
    if(j && (k||!l)&& m) (ans+=MOD - dp[n][j][k][l][m])%=MOD;    
  }

  cout << ans << endl;
  
  return 0;
}

