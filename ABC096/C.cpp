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

//string s[]だとうまくいかない、未定義動作?
//string s[100];
char s[100][100];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int h, w;

//h, w
bool check(int x, int y){
  return (0 <= x && x < h && 0 <= y && y < w);
}

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> h >> w;
  REP(i, h) REP(j, w) cin >> s[i][j];
  
  REP(i, h){
    REP(j, w){
      int cnt = 0;
      if(s[i][j] == '#'){
	REP(k, 4){
	  int x = i+dx[k], y = j+dy[k];
	  if(check(x, y)){
	    if(s[x][y] == '#') cnt++;
	  }
	}
	if(cnt == 0){cout << "No" << endl; return 0;}
      }
    }
  }

  cout << "Yes" << endl;
  
  return 0;
}
