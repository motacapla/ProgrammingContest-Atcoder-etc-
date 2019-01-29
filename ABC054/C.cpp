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

int n, m;
int mat[10][10];
bool visited[10];
ll ans = 0LL;

int dfs(int s){
  bool f = true;
  REP(i, n) if(!visited[i]) f = false;
  if(f) return 1;

  int ret = 0;
  REP(i, n){
    if(mat[s][i] && !visited[i]){
      //true-falseの出入りマン
      visited[i]=true;
      ret += dfs(i);
      visited[i]=false;
    }
  }
  return ret;
}

int
main(void){  
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  REP(i, m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    mat[a][b] = mat[b][a] = 1;
  }

  visited[0] = true;
  cout << dfs(0) << endl;
  
  return 0;
}

  /*
  //解けなかった
  REP(bit, (1<<n)){ //bitDP
    bool visited[n];
    REP(j, n) visited[j] = false;
    REP(j, n){
      if(!(bit%2)) continue;
      if(bit & (1<<j)){ //bitのj番目のビットが立つ
	//cout << bitset<8>(bit) << endl;
	REP(k, n){
	  if((bit & (1<<k)) && mat[j][k] == 1 && !visited[k]){
	    visited[k] = true;
	  }	  
	}
      }
    }
  }
  */
