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
const int MOD=1e9+7;
typedef pair<int, int> P;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

std::string to_binString(unsigned int val)
{
    if( !val )
        return std::string("0");
    std::string str;
    while( val != 0 ) {
        if( (val & 1) == 0 )  // val は偶数か？
            str.insert(str.begin(), '0');  //  偶数の場合
        else
            str.insert(str.begin(), '1');  //  奇数の場合
        val >>= 1;
    }
    return str;
}

/*
  dp[bit] := bitの鍵を使った時の費用の最小値
 */

int n, m;
int a[1050], b[1050], c[1050][20];

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  REP(i, m) {
      cin >> a[i] >> b[i];
      REP(j,b[i]) cin >> c[i][j];  
  }

  const int INF = 1e9;
  vector<int> dp(5010, INF);

  dp[0] = 0;
  
  REP(item, m){
    //current state
    int cur = 0;
    REP(j, b[item]){
      cur |= (1 << (c[item][j]-1));
    }    
    //cerr << to_binString(cur) << endl;

    //bitDP
    REP(bit, (1<<n)){
      dp[bit|cur] = min(dp[bit|cur], dp[bit] + a[item]);
    }
  }

  if(dp[(1 << n) - 1] == INF) dp[(1 << n) - 1] = -1;
  cout << dp[(1 << n) - 1] << endl;  
  return 0;
}
