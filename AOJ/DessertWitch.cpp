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

//解説AC
//1日1回ぐらい、実装して練習したい
//http://imulan.hatenablog.jp/entry/2015/11/19/191919

//int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
//char focus = t[x+res*dx[i]][y+res*dy[i]];

//ROF(i,7,0) ROF(j,7,0) down -> right を優先

//REP(i,n) REP(i,n) up -> left を優先



const int n = 8;
char t[n][n+1];
int all_turn;
int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};

bool check(int row, int col){
  return (row >= 0 && row <= 7 && col >= 0 && col <= 7);
}
void turn(int x, int y, char c){
  char e_c = (c == 'o' ? 'x' : 'o');
  REP(i,n){
    int res = 1;
    while(check(x+res*dx[i], y+res*dy[i])){
      char focus = t[x+res*dx[i]][y+res*dy[i]];
      if(focus == c){
	t[x][y] = c;
	//resまでひっくり返す
	FOR(j,1,res) t[x+j*dx[i]][y+j*dy[i]] = c;
	break;
      }
      else if(focus == e_c) res++;
      else break;
    }
  }    
}
//いくつひっくり返せるか調べる
int simulate(int x, int y, char c){
  int ret = 0;
  char e_c = (c == 'o' ? 'x' : 'o');
  REP(i,n){
    int res = 1;
    while(check(x+res*dx[i], y+res*dy[i])){
      char focus = t[x+res*dx[i]][y+res*dy[i]];
      if(focus == c){
	ret += res-1;
	break;
      }
      else if(focus == e_c) res++;
      else break;
    }
  }  
  return ret;
}
bool solve(){
  int max_n=0, max_x=-1, max_y=-1;
  char c = 'o';

  REP(i,n) REP(j,n){
    if(t[i][j] == '.'){      
      int num = simulate(i,j,c);
      if(max_n<num){
	max_n = num;
	max_x = i;
	max_y = j;
      }
    }
  }
  if(max_x >= 0) turn(max_x, max_y, c);  
  return (max_n > 0);
}

bool _solve(){
  int max_n=0, max_x=-1, max_y=-1;
  char c = 'x';

  ROF(i,7,0) ROF(j,7,0){
    if(t[i][j] == '.'){          
      int num = simulate(i,j,c);
      if(max_n<num){
	max_n = num;
	max_x = i;
	max_y = j;
      }
    }
  }
  if(max_x >= 0) turn(max_x, max_y, c);  
  return (max_n > 0); 
}

int
main(void){  
  ios_base::sync_with_stdio(false);

  REP(i, n) cin >> t[i];

  bool first = true, second = true;
  while(first || second){
    first = solve();
    second = _solve();
  }

  REP(i,n) {
    REP(j,n) cout << t[i][j];
    cout << endl;
  }
  
  return 0;
}
