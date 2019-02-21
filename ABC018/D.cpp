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

//解説AC
//女性だけ全探索, 男性は貪欲
//https://atcoder.jp/contests/abc018/submissions/4196686

int n, m, p, q, r, ans;
int x[400], y[400], z[400];
int a[400];
int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> p >> q >> r;
  REP(i, r) cin >> x[i] >> y[i] >> z[i], x[i]--, y[i]--;

  REP(bit, (1<<n)){
    if(__builtin_popcount(bit) != p) continue;
    //full search
    REP(j,m){
      int sum=0;
      REP(k,r) if((bit&(1<<x[k])) && y[k]==j) sum+=z[k];
      a[j]=sum;
    }
    //greedy    
    int sum = 0;
    sort(a,a+m,greater<int>());
    REP(j,q)sum += a[j];
    ans = max(sum, ans);
  }
  cout << ans << endl;
  return 0;
}
