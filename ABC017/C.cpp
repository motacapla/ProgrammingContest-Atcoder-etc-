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

int l[100001], r[100001], s[100001];
int value[100001];

ll sum = 0LL;
ll ans = 0LL;      

int
main(void){  
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  REP(i, n) cin >> l[i] >> r[i] >> s[i];

  /*
  //TLE
  FOR(i, 1, m+1){
    ll tmp = 0LL;
    REP(j, n){
      if(l[j] <= i && r[j] >= i) continue;
      else tmp += s[j];
    }
    ans = max(ans, tmp);
  }
  */

  //区間の各要素の累積和 ... いもす
  REP(i, n){
    value[l[i]-1] += s[i];
    value[r[i]] -= s[i];
    sum += s[i];
  }

  REP(i, 100000) value[i+1] += value[i];

  /*
  //debug
  cout << "min_element:" << *min_element(value, value+m) << endl;
  REP(i, m) cout << value[i] << " ";
  cout << endl;
  cout << sum << endl;
  */
  
  cout << sum - *min_element(value, value+m) << endl;
    
  return 0;
}
