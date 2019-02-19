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

const int BIT=30, MAXN=1e6;
ll a[BIT][MAXN], ans[MAXN];

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m, d;
  cin >> n >> m >> d;

  REP(i, n) a[0][i] = i;
  
  REP(i, m) {
    int tmp;
    cin >> tmp;
    swap(a[0][tmp-1], a[0][tmp]);
  }
  /*
  REP(i, n) cout << a[0][i]+1 << " ";
  cout << endl;
  */
  
  FOR(i, 1, BIT){
    REP(j, n){
      a[i][j] = a[i-1][a[i-1][j]];
    }
  }

  REP(i, n){
    int parent = i;
    REP(j, BIT){
      if(d & (1<<j)) parent = a[j][parent];      
    }
    //最終的な解 parent の入り口を i とする
    ans[parent] = i;
  }

  REP(i, n) cout << ans[i]+1 << endl;  

  
  return 0;
}
