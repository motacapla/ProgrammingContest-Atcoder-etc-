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

ll nl, nm;

bool is_safe(int n, int v, int ng1, int ng2, int ng3){
  return ((n-v != ng1) && (n-v != ng2) && (n-v != ng3));
}

int
main(void){  
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, ng1, ng2, ng3;
  cin >> n >> ng1 >> ng2 >> ng3;

  if(n == ng1 || n == ng2 || n == ng3) {cout << "NO" << endl; return 0;}
  
  int cnt = 0;
  REP(i, 100){
    if(is_safe(n, 3, ng1, ng2, ng3)) n -= 3;
    else if(is_safe(n, 2, ng1, ng2, ng3)) n -= 2;
    else if(is_safe(n, 1, ng1, ng2, ng3)) n -= 1;
    else {cout << "NO" << endl; return 0;}
    //cout << "i: " << i << " n: " << n << endl;
  }

  cout << (n <= 0 ? "YES" : "NO") << endl;
  
  return 0;
}
