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

//桁, smaller flag
ll dp[1000010][2];

ll solve(void){
  string L;
  cin >> L;
  ll n = L.size();
  dp[0][0] = 1;
  
  REP(i, n) {
    ll d = L[i]-'0';
    REP(j, 2) {
      for(int x=0; x<=(j?1:d); x++){
	/*
	REP(l, lim+1) {	
	  (dp[i+1][j||(l<d)][k||(d==1)||(d==0&&!k)] += (dp[i][j][k]%MOD))%MOD;
	}
	*/
	(dp[i+1][j||x<d] += dp[i][j]*(x+1)%MOD)%=MOD;
      }
    }
  }
  return (dp[n][0] + dp[n][1])%MOD;
}

int
main(void){
  ios_base::sync_with_stdio(false);

  cout << solve() << endl;  

  return 0;
}
