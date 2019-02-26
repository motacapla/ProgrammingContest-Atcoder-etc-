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

int n, w[1010];
int dp[1010][1010];

//解説AC
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2121959#1
//Point3つ

int dfs(int l, int r){
  // Point1. l>= r
  if(l >= r) return 0;
  if(~dp[l][r]) return dp[l][r];  
  int res = 0;
  // Point2. 間が全部抜ける(個数 == r-l-1) & l, rも抜ける
  if( dfs(l+1, r-1) == r-l-1 && abs(w[l]-w[r]) <= 1) res = r-l+1;
  // Point3. dpではなくdfsを入れる
  FOR(mid, l, r) res = max(res, dfs(l, mid)+dfs(mid+1, r));

  return dp[l][r] = res;
}

int
main(void){  
  ios_base::sync_with_stdio(false);

  while(true){
    cin >> n;
    if(n == 0) break;
    REP(i,n) cin >> w[i];
    REP(i, 1010) REP(j, 1010) dp[i][j] = -1;
    cout << dfs(0, n-1) << endl;
  }
  
  return 0;
}
