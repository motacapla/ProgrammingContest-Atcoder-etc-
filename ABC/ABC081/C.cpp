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

vector<int> a;
int cnt[200001];

int
main(void){  
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  REP(i, n) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
    cnt[tmp]++;
  }

  //REP(i, n+1) cout << cnt[i] << endl;  
  
  int kinds = 0;
  FOR(i, 1, n+1) if(cnt[i]) kinds++;
  if(kinds <= k){cout << 0 << endl; return 0;}

  sort(cnt, cnt+n+1);

  //REP(i, n+1) cout << cnt[i] << endl;
  
  ll ans = 0LL;
  FOR(i, 1, n+1){
    if(cnt[i]){
      ans += cnt[i];
      kinds--;
      if(kinds <= k) break;
    }
  }

  cout << ans << endl;
  
  return 0;
}
