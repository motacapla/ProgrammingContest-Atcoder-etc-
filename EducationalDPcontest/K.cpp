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

int n,k;
const int MAX_N = 1000100;
int a[MAX_N];
bool dp[MAX_N];

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  REP(i, n) {
    cin >> a[i];
  }
  //1:相手のターン, 0:自分のターン
  //dp[k]:= k個の局面で勝ち負け
  
  FOR(i,1,k+1){
    REP(j, n){
      if(i-a[j]>=0){
	dp[i] |= !dp[i-a[j]];
      }
    }
    /*
    cout << "i:" << i << endl;
    FOR(j,1,k+1) cout << dp[j] << " ";
    cout << endl;    
    */
  }
  
  FOR(i,1,k+1) cout << dp[i] << " ";
  cout << endl;
 
  cout << (dp[k] ? "First" : "Second") << endl;
  
  return 0;
}
