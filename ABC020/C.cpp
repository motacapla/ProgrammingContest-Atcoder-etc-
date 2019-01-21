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
#define INF 1000000000

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


//https://atcoder.jp/contests/abc020/submissions/4025932
//dijkstraの練習
//midをxに入れる


ll ans = 0LL;
char s[11][11];
int by, bx, ey, ex;

int dy[5]={0,0,1,-1,0};
int dx[5]={1,-1,0,0,0};

typedef tuple<ll, int, int> T;
int h, w, t;

bool dijkstra(int m){
  ll memo[11][11];
  REP(i, 11) REP(j, 11) memo[i][j] = INF*10;
  priority_queue<T, vector<T>, greater<T>> q;
  q.push(make_tuple(0, by, bx));
  memo[by][bx] = 0;
  while(!q.empty()){
    ll c;
    int y, x;
    tie(c, y, x) = q.top(); q.pop();
    REP(i, 4){
      int ny=y+dy[i], nx=x+dx[i];
      if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
      if(s[ny][nx] == '#'){
	if(memo[ny][nx] > c+m){
	  memo[ny][nx] = c+m; // 最小に更新
	  q.push(make_tuple(c+m,ny,nx));
	}
      }
      else{
	if(memo[ny][nx] > c+1){
	  memo[ny][nx] = c+1;
	  q.push(make_tuple(c+1,ny,nx));
	}
      }
    }
  }
  if(memo[ey][ex] <= t) return true;
  else return false;
}

int
main(void){  
  ios_base::sync_with_stdio(false);

  cin >> h >> w >> t;
  REP(i, h) REP(j, w) {
    cin >> s[i][j];
    if(s[i][j] == 'S') {
      by = i;
      bx = j;
    }
    else if(s[i][j] == 'G') {
      ey = i;
      ex = j;
    }
  }

  int l = 0, r = t+1;  
  while(r-l > 1){
    int mid = (l+r)/2;
    if(dijkstra(mid)) l = mid;
    else r = mid;
  }

  cout << l << endl;
  
  return 0;
}
