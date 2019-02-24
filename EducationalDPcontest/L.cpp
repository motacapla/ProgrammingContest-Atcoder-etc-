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

const int MAX_N = 3010;
//解説AC
//https://juppy.hatenablog.com/entry/2019/01/10/EDPC/DP%E3%82%B3%E3%83%B3-L-_C_%E7%AB%B6%E6%8A%80%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0
//dp[i][j]:= a[i]~a[j]まで残ってる状態からのX-Y;
ll dp[MAX_N][MAX_N];
ll a[MAX_N];

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  REP(i,n) cin >> a[i];

  ROF(i, n-1, 0){
    FOR(j, i, n){
      if((n-1-i-j)%2!=0){
	//前 or 後ろの小さい方
	//次郎くんは引く
	dp[i][j] = min(dp[i+1][j]-a[i], dp[i][j-1]-a[j]);
      }
      else{
	//前 or 後ろの大きい方
	//太郎くんは足す
	dp[i][j] = max(dp[i+1][j]+a[i], dp[i][j-1]+a[j]);	
      }
    }
  }
  cout << dp[0][n-1] << endl;
  
  return 0;
}



  /*
//貪欲はng
  REP(i, n) cin>>a, deque.push_back(a);
  ll first = 0LL, second = 0LL;
  bool sente = true;
  while(!deque.empty()){
    ll mae = deque.front();
    ll usiro = deque.back();
    if(mae > usiro) {
      if(sente) {
	first += mae;
	sente = false;
      }
      else {
	second += mae;
	sente = true;
      }
      deque.pop_front();
    }
    else {
      if(sente) {
	first += usiro;
	sente = false;
      }
      else {
	second += usiro;
	sente = true;
      }
      deque.pop_back();
    }
  }
  cout << first-second << endl;
  */

