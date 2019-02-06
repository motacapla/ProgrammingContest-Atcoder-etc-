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

const int MAX = 25;
int dp[MAX][(1<<MAX)];
int a[MAX][MAX];

//解説AC
//https://atcoder.jp/contests/dp/submissions/4182721

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n;  
  cin >> n;
  REP(i, n) REP(j, n) cin >> a[i][j];

  dp[0][(1<<n)-1] = 1;
  REP(i, n){
    REP(bit, (1<<n)){
      //bit数 != n-i
      if(__builtin_popcount(bit) != n-i) continue;
      REP(j, n){
	//好意 かつ j-bit立ってる
	//j-bitを消してプラス, ペアi+1
	if(a[i][j] && (bit&(1<<j))) (dp[i+1][bit&(~(1<<j))] += dp[i][bit])%=MOD;
      }
    }
  }

  cout << dp[n][0] << endl;
  
  return 0;
}
