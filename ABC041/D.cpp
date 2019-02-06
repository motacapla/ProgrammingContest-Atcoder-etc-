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


int g[20][20];
ll dp[1<<20];

int
main(void){
  int n, m, x, y;  
  cin >> n >> m;
  REP(i, m){
    cin >> x >> y;
    x--; y--;
    g[x][y] = 1;
  }
  dp[0] = 1; //空集合 = 1
  REP(bit, (1<<n)){
    REP(j, n){
      //iにjが含まれていたらcontinue
      if((bit>>j) & 1) continue;
      bool f = true;
      //j -> k があるならば、右端 (最速) にこない
      REP(k, n) if(((bit>>k)&1) && g[j][k] == 1) f = false;
      //右端ならば i+{j}=Sの通り数 加える
      if(f) dp[bit|(1<<j)] += dp[bit];
    }
  }

  cout << dp[(1<<n) - 1] << endl;

  return 0;
}

/*
  Recipe:
  1. dp[0] = 1
  2. REP(bit, (1<<n)) REP(j, n)
  3. if j が bit集合に含まれている -> continue
  4. REP(k, n) kはbit集合に含まれていて、k->jに遷移できる -> continue
  5. 遷移できないならば、dp[bit|(1<<j)] += dp[bit]
  6. 解は dp[(1<<n)-1]
*/
