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

int mat[110][110];

int
main(void){  
  int w,h,n,x,y,a;
  
  cin >> w >> h >> n;
    
  REP(i, n){
    cin >> x >> y >> a;
    if(a == 1){
      REP(j, x){
	REP(k, h){
	  ++mat[j][k];
	}
      }
    }
    else if(a == 2){
      FOR(j, x, w){
	REP(k, h){
	  ++mat[j][k];
	}
      }
    }
    else if(a == 3){
      REP(j, w){
	REP(k, y){
	  ++mat[j][k];
	}
      }
    }
    else {
      REP(j, w){
	FOR(k, y, h){
	  ++mat[j][k];
	}
      }
    }    
  }

  int count = 0;
  REP(i, w){
    REP(j, h) {
      if(mat[i][j] == 0){
	++count;
      }
    }
  }

  cout << count << endl;
  
  return 0;
}
