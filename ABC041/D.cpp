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

int n,m;
int g[20][20];

int
main(void){  
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  REP(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a][b] = 1;
  }

  ll dp[1<<n] = {};
  dp[0] = 1; // 空集合のとき、トポソの経路数は1
  REP(i, 1<<n){
    REP(j, n){ // j = iから取り除くうさぎを列挙
      if(i & (1<<j)) continue; // iにjが含まれている場合
      bool f = true; // jが右端か
      //kがiに含まれている && j -> kがあるなら右端にこない
      REP(k, n) if((i & (1<<k)) && g[j][k] == 1) f = false;
      //右端ならi + {j} = Sの通り数に加える
      if(f) dp[i | (1<<j)] += dp[i];
    }
  }

  cout << dp[(1<<n) - 1] << endl;
  
  return 0;
}
