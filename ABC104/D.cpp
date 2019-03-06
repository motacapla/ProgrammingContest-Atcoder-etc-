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

template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

//組み合わせ　初期化は0で　初期値1
ll dp[100010][4];

//解説AC
//https://atcoder.jp/contests/abc104/submissions/2955456
//http://drken1215.hatenablog.com/entry/2018/08/05/224100_1
//1. 状態["","A","AB","ABC"]
//2. 順序 後ろから

void add(long long &a, long long b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  int n = s.size();

  /*
  dp[n][3] = 1;
  ROF(i, n-1, 0){
    ROF(j, 3, 0){      
      if(s[i] == '?'){
	dp[i][j] = dp[i+1][j]*3LL;
      }
      else{
	dp[i][j] = dp[i+1][j]*1LL;
      }      
      if(j < 3){
	if(s[i] == '?' || s[i] == "ABC"[j]){
	  dp[i][j] += dp[i+1][j+1];
	}
      }
      dp[i][j] %= MOD;      
    }
  }
  cout << dp[0][0] << endl;
  */


  dp[0][0] = 1;
  REP(i, n){
    REP(j, 5){
      if(s[i] == '?') add(dp[i+1][j], dp[i][j]*3LL%MOD);
      else add(dp[i+1][j], dp[i][j]);
    }
    if(s[i] == 'A' || s[i] == '?') {
      dp[i+1][1] += dp[i][0];
      dp[i+1][1] %= MOD;
    }
    if(s[i] == 'B' || s[i] == '?') {
      dp[i+1][2] += dp[i][1];
      dp[i+1][2] %= MOD;
    }
    if(s[i] == 'C' || s[i] == '?') {
      dp[i+1][3] += dp[i][2];
      dp[i+1][3] %= MOD;
    }      
  }
  cout << dp[n][3] << endl;
  return 0;
}
