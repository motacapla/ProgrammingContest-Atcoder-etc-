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

int
main(void){  
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, h, a, b, c, d, e;
  cin >> n >> h;
  cin >> a >> b >> c >> d >> e;

  ll x = 0LL;
  ll y = 0LL;
  ll ans = INT_MAX;

  ll hungry = h + x*b + y*d - (n-x-y) * e;
  if(hungry > 0) {cout << "0" << endl; return 0;}

  /*
  ROF(i, n, 0){
    ROF(x, n-i, 0){
      ROF(y, n-x-i, 0){
	if(i+x+y < n) continue;
	//cout << i << " : " << x << " : " << y << endl;
	hungry = h + x*b + y*d - (n-x-y) * e;
	if(hungry > 0) ans = min(ans, x*a+y*c);
      }
    }
  }
  */
    
  REP(i, n+1){
    ll tmp, j;
    tmp = -i*(d+e)+e*n-h; //お腹が減る量
    if(tmp<0) j = 0;//減らない
    else j = tmp/(b+e)+1;
    if(i+j<=n) ans=min(ans, j*a+i*c);
  }
 
  cout << ans << endl;
  
  
  return 0;
}
