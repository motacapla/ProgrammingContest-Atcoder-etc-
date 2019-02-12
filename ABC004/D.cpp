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

const int INF = 1e9;
const int MAXN = 1000;

//解説AC
//https://atcoder.jp/contests/abc004/submissions/4148226
//http://competitive-kivantium.hateblo.jp/entry/2016/12/15/104215

int dp[MAXN][MAXN];
int R, G ,B;

int cost(int pos, int remain){
  if(remain >= G+B) return abs(400-pos);
  else if(remain >= B) return abs(500-pos);
  else return abs(600-pos);
}

int
main(void){  
  ios_base::sync_with_stdio(false);

  cin >> R >> G >> B;

  int total = R+G+B;

  REP(i, MAXN) REP(j, MAXN) dp[i][j] = INF;
  //マーブルを1つも置いてない時は操作回数0  
  REP(i, MAXN) dp[i][total] = 0;

  FOR(i,1,MAXN){
    REP(j, total){
      dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]+cost(i,j));
    }
  }
  int ans = 1e9;
  REP(i, MAXN) ans = min(ans, dp[i][0]);
  
  cout << ans << endl;
  
  return 0;
}
