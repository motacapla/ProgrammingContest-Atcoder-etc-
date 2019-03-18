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

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  char a[110][110], ans[110][110];
  cin >> h >> w;
  REP(i, h) REP(j, w) cin >> a[i][j];

  int idx = 0, jdx = 0;
  REP(i, h) {
    bool ok = true;
    REP(j, w) if(a[i][j] == '#') ok = false;
    if(!ok){
      REP(j, w) ans[idx][j] = a[i][j];
      idx++;
    }    
  }

  REP(j, w) {
    bool ok = true;
    REP(i, h) if(a[i][j] == '#') ok = false;
    if(!ok){
      REP(i, h) ans[i][jdx] = ans[i][j];
      jdx++;
    }    
  }  
  
  REP(i, idx) {
    REP(j, jdx) cout << ans[i][j];
    cout << endl;
  }
  return 0;
}
