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

const int MAXN = 1e9;
int table[20][20];
ll ans = 0LL;
int n;
int dp[20][(1<<16)];

void func(){
  int lim = (1<<n);
  
  REP(i, n) REP(j, n+1) cin >> table[i][j];
  //nステージクリアなので、nまで更新するのに気をつける
  REP(j, n+1) REP(i, lim) dp[j][i] = MAXN;
  
  bool used[n];
  REP(i, n) dp[1][(1<<i)] = table[i][0];
    
  FOR(i, 2, n+1){
    REP(bit, lim){
      //i-1番目がMAXNじゃないとき じゃないとTLE
      if(dp[i-1][bit] != MAXN){
	REP(j, n){
	  if(bit & (1<<j)) used[j] = true;
	  else used[j] = false;
	}
	REP(j, n){
	  if(!used[j]){
	    //bit立てる
	    int tmp = bit | (1<<j);
	    REP(k, n){
	      //k番目のbitが立っているとき、j番目のbitを立てた場合 vs j番目のbitをたてずに既に立っているk番目のbitを使ったときの最小値　比較
	      if(used[k]) dp[i][tmp] = min(dp[i][tmp], dp[i-1][bit] + min(table[j][0], table[j][k+1]));
	      else dp[i][tmp] = min(dp[i][tmp], dp[i-1][bit]+table[j][0]);
	    }
	  }
	}
      }
    }
  }
  //bit: 1,1,...,1 のときのn全部クリア
  cout << dp[n][lim-1] << endl;
}

int
main(void){  
  ios_base::sync_with_stdio(false);

  while(true){
    cin >> n;
    if(n == 0)break;
    func();
  }
    
  return 0;
}
