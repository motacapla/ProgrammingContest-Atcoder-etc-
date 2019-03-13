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

//解説AC
//https://www.hamayanhamayan.com/entry/2018/09/07/232917
//O(N2^N)

const int INF = 1<<29;
int T, N;
int t[1000010];
int dp[1<<17];
bool ok[1<<17];

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> T >> N;
  REP(i,N) cin >> t[i];   

  REP(bit,1<<N){
    int sm = 0;
    REP(i,N) if(bit & (1<<i)) sm += t[i];
    if(sm <= T) ok[bit] = true;
  }

  REP(bit,1<<N) dp[bit] = INF;
  dp[0] = 0;
  REP(bit,1<<N){
    for(int msk = bit; msk > 0; msk = (msk-1)&bit){
      //cerr << "bit:" << bitset<9>(bit) << " msk: " << bitset<9>(msk) << endl;
      if(ok[msk]) chmin(dp[bit], dp[bit-msk]+1);
    }
  }
  cout << dp[(1<<N)-1] << endl;
  return 0;
}
