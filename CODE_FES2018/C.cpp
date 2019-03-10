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

ll n, m;
pair<ll, ll> ab[101010];
ll a[101010], t[101010];

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  REP(i, n) cin >> ab[i].first >> ab[i].second;  
  sort(ab, ab+n);
  REP(i, n) a[i] = ab[i].first;

  cin >> m;
  REP(i, m) cin >> t[i];
  //sort(t, t+m);

  REP(i, m){
    ll cnt = 0;
    int j = lower_bound(a, a+n, t[i])-a;
    //ピッタリ見つかる
    if(ab[j].first == t[i]) cnt += ab[j].second;
    //空
    else if(j == 0) cnt += ab[j].second;
    //超える
    else if(j == n) cnt += ab[j-1].second + t[i] - ab[j-1].first;
    //その他
    else cnt += min(ab[j].second, ab[j-1].second + t[i] - ab[j-1].first);
    cout << cnt << endl;
  }
  
  return 0;
}
