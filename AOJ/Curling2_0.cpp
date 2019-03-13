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
#include <stack>
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

template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

int W, H, ans, cnt, turn;
int table[25][25];
P curr, goal;

void solve(P point){
  if(turn != 11){
    turn++;
    int x = point.first, y = point.second;
    int t = table[x+1][y];
    if(t == 0 || t == 3){
      FOR(i, x+1, H){
	if(table[i][y] == 3 && turn < cnt){
	  cnt = turn;
	  break;
	}
	if(table[i][y]==1){
	  table[i][y] = 0;
	  solve(make_pair(i-1,y));
	  table[i][y] = 1;
	  break;
	}
      }
    }

    t = table[x-1][y];
    if(t == 0 || t == 3){
      ROF(i, x-1, 0){
	if(table[i][y] == 3 && turn < cnt){
	  cnt = turn;
	  break;
	}
	if(table[i][y]==1){
	  table[i][y] = 0;
	  solve(make_pair(i+1,y));
	  table[i][y] = 1;
	  break;
	}
      }
    }

    t = table[x][y+1];
    if(t == 0 || t == 3){
      FOR(i, y+1, W){
	if(table[x][i] == 3 && turn < cnt){
	  cnt = turn;
	  break;
	}
	if(table[x][i]==1){
	  table[x][i] = 0;
	  solve(make_pair(x,i-1));
	  table[x][i] = 1;
	  break;
	}
      }
    }
    

    t = table[x][y-1];
    if(t == 0 || t == 3){
      ROF(i, y-1, 0){
	if(table[x][i] == 3 && turn < cnt){
	  cnt = turn;
	  break;
	}
	if(table[x][i]==1){
	  table[x][i] = 0;
	  solve(make_pair(x,i+1));
	  table[x][i] = 1;
	  break;
	}
      }
    }
    turn--;
  } 
}

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  while(true){
    cin >> W >> H;
    if(W == 0 && H == 0) break;
    cnt=11;
    REP(i, H) REP(j, W) {
      cin >> table[i][j];
      if(table[i][j] == 2) curr.first = i, curr.second = j;
    }
    turn = 0;
    table[curr.first][curr.second] = 0;
    solve(curr);
    if(cnt == 11) cout << -1 << endl;
    else cout << cnt << endl;
  }

    
  
  return 0;
}
