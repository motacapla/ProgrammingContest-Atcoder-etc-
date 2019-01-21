//$g++ -std=c++11 Template.cpp 

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

priority_queue<int> q_descending;
priority_queue<int, vector<int>, greater<int> > q_ascending;

ll c[202][202];
const ll INF = 1e10;
bool used[575];
ll num[575];

void warshall_floyd(int n) { // nは頂点数
  REP(k, n) REP(i, n) REP(j, n) c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
}
// http://kmjp.hatenablog.jp/entry/2015/04/11/0900

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n, m, a, b, x, y;
  cin >> n >> a >> b >> m;
  a--; b--;  
  REP(i, 202) REP(j, 202) {c[i][j] = INF; if(i == j) c[i][j] = 0;}
  REP(i, m) { cin >> x >> y; x--; y--; c[x][y]=1; c[y][x]=1;}  

  warshall_floyd(n);
  //check
  //REP(i, n) {REP(j, n) {cout << c[i][j] << " ";} cout << endl;}

  num[a] = 1;
  REP(i, n){
    REP(cur, n){
      if(c[a][cur] != i) continue;
      REP(tar, n){
	if(c[a][tar] == i+1 && c[cur][tar] == 1){
	  num[tar] += num[cur];
	  num[tar] %= MOD;
	}
      }
    }
  }
  
  cout << num[b] << endl;
  
  return 0;
}

  /*
  //WA, ゴール部分のハンドリング
  queue<int> q;
  a--; b--;
  q.push(a);
  
  while(!q.empty()){    
    int c = q.front(); q.pop();
    if(!used[c]){
      int num = 0, num_b = 0;
      used[c] = true;      
      REP(i, n) {
	//ゴールがある
	if(d[b][c] == 1 && !used[b]){
	  num_b++;
	}
	//その他
	else if(d[i][c] == 1 && !used[i]){
	  num++;
	  q.push(i);
	}
      }
      if(num_b > 0) break;
      else ans *= num; ans %= MOD;
    }
  }
  */
  
