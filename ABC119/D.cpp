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

template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

ll A, B, Q;
ll s[100010], t[100010], x[100010];
//解説AC
//s x tでx->t->sと訪れるのと、t x sで x->t->sと訪れるのは違う

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  s[0] = -1e18; t[0] = -1e18;
  
  cin >> A  >> B >> Q;
  FOR(i,1,A+1) cin >> s[i];
  FOR(i,1,B+1) cin >> t[i];
  REP(i, Q) cin >> x[i];

  s[A+1] = 1e18; t[B+1] = 1e18;
  
  const ll INF = 1e18;
  
  REP(i, Q){
    ll a = upper_bound(s+1, s+A+1, x[i]) - s;
    ll b = upper_bound(t+1, t+B+1, x[i]) - t;
    //cout << a << " " << b << endl;
    ll mini = INF;

    //calc
    FOR(j,a-1,a+1){
      FOR(k,b-1,b+1){	
	mini = min(mini, min(abs(x[i]-s[j])+abs(s[j]-t[k]),abs(x[i]-t[k])+abs(s[j]-t[k])));
      }
    }
    
    cout << mini << endl;
  }
  
  return 0;
}
