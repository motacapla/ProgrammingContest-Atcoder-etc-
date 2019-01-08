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

//nim?
/*

who wins
n == 1 ... x = 2, 3 -> a
n == 2 ... x = 2, -> t
n == 3 ... x = 3, -> t
n == 4 ... x = 3 -> x = 5, 6, 7 -> a
n == 5 ... x = 3 -> t
n == 6 ... x = 3 -> x = 6 -> a 

x = n, n-1, ...,  を読んだらwin
x = n/2 を読んだらlose
x = n/2/2 を読んだらwin
...
if(n ==)

if(n == 2x) x = 2x;
else x = 2x + 1;

*/

int
main(void){  
  ll n;
  cin >> n;
  if(n == 1){cout << "Aoki" << endl; return 0;}

  ll cnt = 0LL;
  ll ntmp = n;
  while(ntmp>0){
    cnt++;
    ntmp = ntmp/2;
  }

  ll t = cnt % 2 == 0 ? 0 : 1;
  ll a = cnt % 2 == 0 ? 1 : 0;

  ll x = 1LL;
  bool t_turn = true;
  while(x<=n){
    x = 2*x + (t_turn ? t : a);
    t_turn = !t_turn;
  }
  if(t_turn) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
  
  return 0;
}
