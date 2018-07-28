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


int
main(void){  
  int n;
  string s;
  cin >> n;

  int v[n][30] = {};

  
  REP(i, n){
    cin >> s;
    REP(j, s.size()){
      int itmp = (int)s[j]-97;
      v[i][itmp]++;
    }
  }
  
  /*
  REP(i, n){    
    REP(j, 26) cout << "v :i,j " << v[i][j] << endl;
  }
  */

  int res[30] = {};
  REP(i, 30) res[i] = INT_MAX;
  
  REP(i, n) REP(j, 26) if(v[i][j] < res[j]) res[j] = v[i][j];

  REP(i, 26) {
    while(res[i] > 0) {
      cout << (char)('a'+ i);
      res[i]--;
    }
  }

  cout << endl;
  
  return 0;
}
