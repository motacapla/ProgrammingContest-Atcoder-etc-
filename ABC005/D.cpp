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
//http://competitive-kivantium.hateblo.jp/entry/2016/12/14/144030

int D[55][55];
int acc[55][55];
int p[2501];
int memo[2501];

int area(int x, int y, int w, int h){
  return acc[x+w][y+h]-acc[x+w][y]-acc[x][y+h]+acc[x][y];
}
int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n;
  REP(i, n) REP(j, n) cin >> D[i][j];
  cin >> q;
  REP(i, q) cin >> p[i];

  REP(i, n+1) acc[0][i] = 0;
  FOR(i,1,n+1){
    int row = 0;
    acc[i][0] = 0;
    FOR(j,1,n+1){
      row += D[i-1][j-1];
      acc[i][j] = acc[i-1][j] + row;
    }
  }
  /*
  REP(i, n+1) {
    REP(j, n+1) cout << acc[i][j] << " ";
    cout << endl;
  }  
  */
  REP(i, 2501) memo[i] = 0;
  REP(w, n+1){
    REP(h, n+1){
      REP(x, n-w+1){
	REP(y, n-h+1){
	  memo[w*h] = max(memo[w*h], area(x,y,w,h));
	}
      }
    }
  }

  FOR(i,1,2501) memo[i] =max(memo[i],memo[i-1]);
  
  REP(i, q) cout << memo[p[i]] << endl;
  
  return 0;
}
