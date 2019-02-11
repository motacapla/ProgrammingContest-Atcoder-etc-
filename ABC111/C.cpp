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

int v[100100];
int cnt_even[100100], cnt_odd[100100];

const int INF=1e9;
vector<int> even, odd;

int
main(void){  
  int n;
  cin >> n;
  REP(i, n) {
    cin >> v[i];
    if(i%2) cnt_odd[v[i]]++;
    else cnt_even[v[i]]++;
  }

  vector<P> e, o;
  REP(i, 100100){
    e.push_back(make_pair(cnt_even[i], i));
    o.push_back(make_pair(cnt_odd[i], i));    
  }

  sort(e.begin(), e.end(), greater<P>());
  sort(o.begin(), o.end(), greater<P>());

  if(e[0].second != o[0].second) cout << n-e[0].first-o[0].first << endl;
  else cout << min(n-e[0].first-o[1].first, n-e[1].first-o[0].first) << endl;
  
  return 0;
}
