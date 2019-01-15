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

int a[100001];
int b[100001];
int c[100001];
int dp[100001][5];

void PRINT(int n, int m){
  
  cout << "----" << endl;
  REP(i, n) {
    REP(j, m) {cout << dp[i][j] << " ";}
    cout << "\n";
  }
  cout << "----" << endl;
}

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n;  
  cin >> n;

  REP(i, n) cin >> a[i] >> b[i] >> c[i];

  REP(i, n) REP(j, 3) dp[i][j] = 0;

  dp[0][0] = a[0];
  dp[0][1] = b[0];
  dp[0][2] = c[0];

  //PRINT(n, 3);
  
  // j = 0,1,2 -> a, b, c
  REP(i, n){
    REP(j, 3){
      /*
      if(j == 0) dp[i+1][j] = max(max(dp[i][1]+a[i+1], dp[i][1]+c[i+1]), max(dp[i][2]+a[i+1], dp[i][2]+b[i+1]));
      else if(j == 1) dp[i+1][j] = max(max(dp[i][0]+b[i+1], dp[i][0]+c[i+1]), max(dp[i][2]+a[i+1], dp[i][2]+b[i+1]));
      else dp[i+1][j] = max(max(dp[i][0]+b[i+1], dp[i][0]+c[i+1]), max(dp[i][1]+a[i+1], dp[i][1]+c[i+1]));
      */

      if(j == 0) dp[i+1][j] = max(dp[i][1], dp[i][2]) + a[i+1];
      else if(j == 1) dp[i+1][j] = max(dp[i][0], dp[i][2]) + b[i+1];
      else dp[i+1][j] = max(dp[i][0], dp[i][1]) + c[i+1];
    }
    //PRINT(n, 3);    
  }
  //dp[i+k] = min(dp[i+k], dp[i+j]+abs(h[i+j]-h[i+k]));      
  
  cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << endl;
  
  return 0;
}
