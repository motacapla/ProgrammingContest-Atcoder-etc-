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

priority_queue<int> q_descending;
priority_queue<int, vector<int>, greater<int> > q_ascending;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int mat[21][21];
int t[4][20][20];
P s;
int w, h, ans;

bool check(int r, int c){
  if(r >= 0 && r < h && c >= 0 && c < w) return true;
  else return false;
}
//再帰
//
void dfs(int r, int c, int cnt){
  if(mat[r][c] == 3){
    if(ans == -1) ans = cnt;
    else ans = min(ans, cnt);
    return ;
  }

  if(ans != -1 && cnt >= ans) return;
  if(cnt == 10) return;

  REP(i, 4) REP(j, h) REP(k, w) t[i][j][k] = mat[j][k];

  if(check(r-1,c) == true && mat[r-1][c] != 1){
    if(mat[r-1][c] == 3){
      dfs(r-1,c,cnt+1);
      return;
    }
    for(int k = 2; check(r-k, c) == true; k++){
      if(mat[r-k][c] == 3){
	dfs(r-k,c,cnt+1);
	return;
      }
      else if(mat[r-k][c] == 1){
	t[0][r-k][c] = 0;
	dfs(r-k+1,c,cnt+1);
      }
    }
  }

  if(check(r+1,c) == true && mat[r+1][c] != 1){
    if(mat[r+1][c] == 3){
      dfs(r+1,c,cnt+1);
    }
    for(int k = 2; check(r+k, c) == true; k++){
      if(mat[r+k][c] == 3){
	dfs(r+k,c,cnt+1);
	return;
      }
      else if(mat[r+k][c] == 1){
	t[1][r+k][c] = 0;
	dfs(r+k-1,c,cnt+1);
      }
    }    
  }

  if(check(r,c-1) == true && mat[r][c-1] != 1){
    if(mat[r][c-1] == 3){
      dfs(r,c-1,cnt+1);
    }
    for(int k = 2; check(r, c-k) == true; k++){
      if(mat[r][c-k] == 3){
	dfs(r,c-k,cnt+1);
	return;
      }
      else if(mat[r][c-k] == 1){
	t[2][r][c-k] = 0;
	dfs(r,c-k+1,cnt+1);
      }
    }    
  }

  if(check(r,c+1) == true && mat[r][c+1] != 1){
    if(mat[r][c+1] == 3){
      dfs(r,c+1,cnt+1);
    }
    for(int k = 2; check(r, c+k) == true; k++){
      if(mat[r][c+k] == 3){
	dfs(r,c+k,cnt+1);
	return;
      }
      else if(mat[r][c+k] == 1){
	t[3][r][c+k] = 0;
	dfs(r,c+k-1,cnt+1);
      }
    }    
  }   
}

int
main(void){  
  ios_base::sync_with_stdio(false);

  while(true){  
    cin >> w >> h;
    if(w == 0 && h == 0) break;
    REP(i, h){
      REP(j, w) {
	cin >> mat[i][j];
	if(mat[i][j] == 2) {s.first = i; s.second = j;}      
      }
    }
    ans = -1;
    dfs(s.first, s.second, 0);
    cout << ans << endl;
  }
  
  return 0;
}
