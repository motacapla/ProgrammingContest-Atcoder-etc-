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

ll n, d, x, y;
ll rl,ud,l;
long double fact[1010], p;

//n <= 1000
long double nCr(long n,long m){return (fact[n]/fact[m])/fact[n-m];}
 
void init(){
  fact[0]=1;
  for(int i=1;i<1010;i++)fact[i]=fact[i-1]*i;
}

int
main(void){  
  ios_base::sync_with_stdio(false);

  init();
  
  cin >> n >> d >> x >> y;
  if(x%d||y%d){cout << 0 << endl; return 0;}
  
  x = abs(x);
  y = abs(y);
  x/=d;
  y/=d;
  FOR(i, x, n-y+1){
    rl = i;
    ud = n-i;
    if((rl-x)%2 || (ud-y)%2) continue;
    l = (rl-x)/2;
    d = (ud-y)/2;
    p += nCr(n, rl)*nCr(rl, l)*nCr(ud,d);
  }
  REP(i, n) p/=4.0;
  cout << setprecision(30) << p << endl;
  return 0;
}
