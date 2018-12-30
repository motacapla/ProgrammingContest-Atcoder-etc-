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

ll dp[20][2][2];

ll calc(ll x){
  string s = to_string(x);
  int n = s.size();
  memset(dp, 0, sizeof(dp));

  dp[0][0][0] = 1;
  REP(i, n) REP(j, 2) REP(k, 2){
    if(dp[i][j][k] == 0) continue;
    int lim = (j?9:s[i]-'0'); 
    REP(num, lim+1) dp[i+1][j||num<lim][k||num==4||num==9] += dp[i][j][k];
  }
  ll res = dp[n][0][1] + dp[n][1][1];
  return res;
}

int
main(void){  
  ios_base::sync_with_stdio(false);

  ll a, b;
  cin >> a >> b;
  a--;

  cout << calc(b) - calc(a) << endl;
  
  /* 
     桁DB
     0 ~ N に含まれる禁止の数 f(N)
     dp[i][j][k]: i桁目まで確定  N未満であることが確定しているorいないj=1or0  数列に4, 9が含まれないor含まれるk=1or0 (非0真なため)

     //分かりやすいブログ
     http://torus711.hatenablog.com/entry/20150423/1429794075

     例. N = 12345
     123?? -> 3桁目が"3"なら4桁目は"1, 2, 3, 4"(=D), 違うなら"0, ..., 9"どれでも良い
     
  */
  
  
  return 0;
}
