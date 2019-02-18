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

//解説AC
//経路復元!!
//https://atcoder.jp/contests/dp/submissions/4313185

//dp[i][j] := sのi番目, tのj番目までみたときの一致した文字数
ll dp[3010][3010];

int
main(void){  
  ios_base::sync_with_stdio(false);

  string s, t;
  cin >> s >> t;
  int ns = s.size(), nt = t.size();

  
  REP(i, ns){
    REP(j, nt){
      if(s[i] == t[j]){
	dp[i+1][j+1] = dp[i][j] + 1;
      }
      else{
	dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
      }
    }
  }

  string ans;
  int i = ns, j = nt;
  //遡る
  while(i > 0 && j > 0){
    if(dp[i][j] == dp[i-1][j]) --i;
    else if(dp[i][j] == dp[i][j-1]) --j;
    else{
      ans = s[i-1] + ans;
      --i, --j;
    }
  }
  cout << ans << endl;
  
  return 0;
}
