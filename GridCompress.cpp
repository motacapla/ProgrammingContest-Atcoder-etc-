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

const int MAX_N = 1e3;
int W, H, N;
int X1[MAX_N], X2[MAX_N], Y1[MAX_N], Y2[MAX_N];
bool fld[MAX_N*6][MAX_N*6];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int compress(int *x1, int *x2, int w){
  vector<int> xs;
  REP(i, N) FOR(d, -1, 2){
    int tx1=x1[i]+d, tx2=x2[i]+d;
    if(1<=tx1 && tx1<= W) xs.push_back(tx1);
    if(1<=tx2 && tx2<= W) xs.push_back(tx2);    
  }
  sort(xs.begin(), xs.end());

  //for(auto &v: xs) cout << v << endl;
  //重複排除    
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  //for(auto &v: xs) cout << ":" << v << endl;

  REP(i, N){
    x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
    x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();    
  }
  return xs.size();
}

int
main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> W >> H >> N;
  REP(i, N) cin >> X1[i];
  REP(i, N) cin >> X2[i];
  REP(i, N) cin >> Y1[i];
  REP(i, N) cin >> Y2[i];
  
  W=compress(X1, X2, W);
  H=compress(Y1, Y2, H);

  
  memset(fld, 0, sizeof(fld));
  REP(i, N){
    FOR(y, Y1[i], Y2[i]+1){
      FOR(x, X1[i], X2[i]+1){
	//cout << y << " " << x << endl;
	fld[y][x] = true;
      }
    }
  }
  
  int ans = 0;
  REP(y, H){
    REP(x, W){
      if(fld[y][x]) continue;
      ans++;

      queue<pair<int,int>> que;
      que.push(make_pair(x,y));
      while(!que.empty()){
	int sx = que.front().first, sy = que.front().second;
	que.pop();
	REP(i, 4){
	  int tx=sx+dx[i], ty=sy+dy[i];
	  if(tx < 0 || W <= tx || ty < 0 || H <= ty) continue;
	  if(fld[ty][tx]) continue;
	  //cout << ty << " " << tx << endl;
	  que.push(make_pair(tx, ty));
	  fld[ty][tx] = true;
	}
      }
    }
  }
  cout << ans << endl;
  
}


/*
Input:
10 10 5
1 1 4 9 10
6 10 4 9 10
4 8 1 1 6
4 8 10 5 10

Output:
6
 */
