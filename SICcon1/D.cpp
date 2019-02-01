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

ll nl, nm;
ll a[10000001];

set<int> vs, vst, res;
//TLEったのでmultisetで書き直しした -> TLEった -> bitでやるか.. -> WA
//多分, 表現範囲を超えている? 10^6だし
//ll bit, bitt;

int
main(void){  
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  REP(i, m) cin >> a[i];
  bool f = false;
  ll minlen = 1e9+1, sum = 0LL;
  int r = 0;
  REP(l, m){    
    while(r < m && sum < n){
      sum += a[r];
      r++;
    }
    if(minlen > r-l && sum >= n){      
      minlen = r-l;
      vs.clear(); vst.clear();
      vs.insert(l); vst.insert(r);
      //bit = 0;      
      //FOR(i, l, r) bit |= (1<<i);
      //cout << "bit: " << bitset<10>(bit) << " bitt:" << bitset<10>(bitt) << endl;            
    }
    else if(minlen == r-l && sum >= n){
      //bitt = 0;
      //FOR(i, l, r) bitt |= (1<<i);
      //bit = bit & bitt;
      //cout << "bit: " << bitset<10>(bit) << " bitt:" << bitset<10>(bitt) << endl;
      vs.insert(l);
      vst.insert(r);
    }
    if(l == r) r++;
    else sum -= a[l];    
  }
  //cout << __builtin_popcount(bit) << endl;

  if(vs.size()) cout << max(0, *vst.begin() - *vs.rbegin()) << endl;
  else cout << "0" << endl;
  
  return 0;
}
