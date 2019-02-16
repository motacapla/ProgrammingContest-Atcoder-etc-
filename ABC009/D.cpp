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
//https://atcoder.jp/contests/abc009/submissions/4255266
//蟻本 pp.181

ll k,m,a[100],b[100],c[100][100],d[100][100];

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> k >> m;
  REP(i, k) cin >> a[k-i-1];
  REP(i, k) cin >> c[0][i];
  REP(i, k-1) c[i+1][i] = -1;
  if(m <= k){
    cout << a[k-m] << endl;
    return 0;
  }  
  m-=k;
  while(m>0){
    if(m&1){
      REP(i, k){
	b[i]=a[i];
	a[i]=0;
      }
      REP(i, k){
	REP(j, k){
	  a[i] ^= b[j]&c[i][j];
	}
      }
    }
    REP(i, k){
      REP(j, k){
	d[i][j] = c[i][j];
	c[i][j] = 0;
      }
    }
    REP(i, k){
      REP(j, k){
	REP(l, k){
	  c[i][j] ^= d[i][l]&d[l][j];
	}
      }
    }
    m >>= 1;
  }
  cout << a[0] << endl;
  
  return 0;
}
