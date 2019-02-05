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


//i桁目, mod 3, 3がつく
ll dp[32][3][2];

ll calc(string s){
  memset(dp, 0, sizeof(dp));
  int n = 0;
  while(true){
    if(s[n] == '.') break;
    n++;
  }
  n--;
  dp[0][0][0] = 1;
  REP(i, n) {
    REP(j, 3){
      REP(k, 2){
	//条件なくても間に合うなら d = 0~9まで試す
	REP(d, 10) dp[i+1][(j*10+d)%3][k|(d == 3)] += dp[i][j][k];
      }
    }  
  }
  ll ans = 0LL;
  //ここがわからんかった... 
  //ans = dp[n][0][0] + dp[n][0][1] + dp[n][1][1] + dp[n][2][1];  
  return ans;
}

int
main(void){  
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll p;
  cin >> p;
  string a = to_string(pow(10, p));

  //cout << a << endl;  
  cout << calc(a) - 1 << endl;
  
  return 0;
}
