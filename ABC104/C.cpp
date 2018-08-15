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
  ll d, g;
  cin >> d >> g;
  int p[d];
  ll c[d];

  REP(i, d) {
    cin >> p[i] >> c[i];
  }

  bool f=false;
  int ans=0;
  ll sum = 0;
  ROF(i, d-1, 0){
    f = false;
    while(p[i]>0){
      sum += (i+1)*100;
      ans++;
      p[i]--;
      if(sum == g){
	f=true;
	break;
      }
      else if(sum > g) {
	sum -= (i+1)*100;
	ans--;
	p[i]++;
	break;
      }
    }
    if(sum == g || f){      
      break;
    }    
    if(p[i] == 0){
      sum += c[i];
    }
  }
  
  cout << ans << endl;
  
  return 0;
}
