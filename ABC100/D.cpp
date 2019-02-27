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
#include <bitset>
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

ll xyz[1010][3];


int
main(void){  
  int n, m;
  cin >> n >> m;

  ll ans=0;

  REP(i, n) REP(j, 3) cin >> xyz[i][j];
  
  // 001 ... xy -z
  REP(bit, (1<<3)){
    vector<ll> v;    
    REP(i, n){
      ll tmp = 0;      
      REP(j, 3){
	if(bit & (1<<j)) tmp -= xyz[i][j];       
	else tmp += xyz[i][j];	
	//cout << bitset<3>(bit) << " i: " << i << " j:" << j << " sum:" << tmp << endl; 	
      }
      v.push_back(tmp);
    }
    sort(v.begin(), v.end(), greater<ll>());
    ll res = 0;
    REP(i, m) res += v[i];    
    ans = max(ans, res);
  }
  cout << ans << endl;  
  return 0;
}
