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

//http://www.geocities.jp/p_lan_c/arg02.html

// 最大公約数を求める関数
ll gcd(ll x, ll y)
{
    ll r;

    if(x == 0 || y == 0)  // 引数チェック
    {
        fprintf(stderr, "引数エラーです。\n");
        return 0;
    }

    // ユーグリッドの互除法
    while((r = x % y) != 0) // yで割り切れるまでループ
    {
        x = y;
        y = r;
    }
    return y;
}

// 最大公約数を求める関数
ll lcm(ll x, ll y)
{
    if(x == 0 || y == 0)  // 引数チェック
    {
        fprintf(stderr, "引数エラーです。\n");
        return 0;
    }

    return (x * y / gcd(x, y));
}

//ちゃんと整備しましょう or C++17を使いましょう

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;

  ll ans = lcm(n, m);
  ll v = gcd(n,m);
  ll idx = ans/m, jdx = ans/n;
  
  REP(i, v){
    if(s[idx*i] != t[jdx*i]){
      cout << -1 << endl;
      return 0;
    }
  }  
  cout << ans << endl;

  return 0;
}
