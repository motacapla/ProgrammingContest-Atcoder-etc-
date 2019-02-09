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

char mat[15][15]; // ¥n
char* zero = (char*)"0";
char* one = (char*)"1";

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool check(int x, int y){
  if(0 <= x && x <= 11 && 0 <= y && y <= 11) return true;
  else false;
}
void dfs(int x, int y){
  mat[x][y] = zero[0];  
  REP(k, 4){
    int xx = x+dx[k], yy = y+dy[k];
    if(check(xx, yy) && mat[xx][yy] == one[0]) dfs(xx, yy);          
  }
}

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n = 12;
  while(scanf("%s",mat[0])!=EOF){
    for(int i=1; i <= n-1; i++){
      scanf("%s",mat[i]);
    }
    getchar();  
    ll ans = 0LL;    

    //REP(i, n) REP(j, n) cin >> mat[i][j];
    REP(i, n) REP(j, n) if(mat[i][j] == one[0]) {dfs(i,j); ans++;}
    cout << ans << endl;
  }
    
  
  return 0;
}
