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
#include <stack>
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

template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

// k<=max(3000)
ll x, y, z, k;
ll a[1010], b[1010], c[1010];

int cnt_a, cnt_b, cnt_c;

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> x >> y >> z >> k;
  
  REP(i, x) cin >> a[i];
  REP(i, y) cin >> b[i];
  REP(i, z) cin >> c[i];

  sort(a, a+x, greater<ll>());
  sort(b, b+y, greater<ll>());
  sort(c, c+z, greater<ll>());

  vector<ll> ab, ans;
  REP(i, x) REP(j, y) ab.push_back(a[i]+b[j]);  
  sort(ab.begin(), ab.end(), greater<ll>());
  
  int tmp = min((int)k, (int)ab.size());
  
  REP(i, tmp) REP(j, z){
    ans.push_back(ab[i] + c[j]);
  }

  sort(ans.begin(), ans.end(), greater<ll>());
  
  REP(i, k) cout << ans[i] << endl;

  return 0;
}
