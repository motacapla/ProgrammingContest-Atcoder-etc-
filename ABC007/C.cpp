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

char board[51][51];
bool visited[51][51];
int number[51][51];
P p;

int
main(void){  
  ios_base::sync_with_stdio(false);

  int r, c;
  int sy, sx, gy, gx;
  cin >> r >> c >> sy >> sx >> gy >> gx;

  REP(i, r){
    REP(j, c){
      cin >> board[i+1][j+1];
    }
  }
  
  queue<P> q;
  
  p.first = sy;
  p.second = sx;
  
  q.push(p);
  visited[sy][sx] = true;
  number[sy][sx] = 0;
  
  while(q.size()){
    P tmp_p = q.front(), tmpp_p;
    q.pop();

    //cout << "current:" << tmp_p.first << " : " << tmp_p.second << endl;
    
    if(tmp_p.first == gy && tmp_p.second == gx) break;
    
    //up
    if( (board[tmp_p.first-1][tmp_p.second] == '.') && (!visited[tmp_p.first-1][tmp_p.second]) ){
      tmpp_p.first = tmp_p.first-1;
      tmpp_p.second = tmp_p.second;
      number[tmpp_p.first][tmpp_p.second] = number[tmp_p.first][tmp_p.second] + 1;
      visited[tmp_p.first-1][tmp_p.second] = true;      
      q.push(tmpp_p);      
    }
    //down
    if( (board[tmp_p.first+1][tmp_p.second] == '.') && (!visited[tmp_p.first+1][tmp_p.second]) ){
      tmpp_p.first = tmp_p.first+1;
      tmpp_p.second = tmp_p.second;
      number[tmpp_p.first][tmpp_p.second] = number[tmp_p.first][tmp_p.second] + 1;
      visited[tmp_p.first+1][tmp_p.second] = true;
      q.push(tmpp_p);      
    }
    //left
    if( (board[tmp_p.first][tmp_p.second-1] == '.') && (!visited[tmp_p.first][tmp_p.second-1]) ){
      tmpp_p.first = tmp_p.first;
      tmpp_p.second = tmp_p.second-1;
      number[tmpp_p.first][tmpp_p.second] = number[tmp_p.first][tmp_p.second] + 1;
      visited[tmp_p.first][tmp_p.second-1] = true;      
      q.push(tmpp_p);      
    }
    //right
    if( (board[tmp_p.first][tmp_p.second+1] == '.') && (!visited[tmp_p.first][tmp_p.second+1]) ){
      tmpp_p.first = tmp_p.first;
      tmpp_p.second = tmp_p.second+1;
      number[tmpp_p.first][tmpp_p.second] = number[tmp_p.first][tmp_p.second] + 1;
      visited[tmp_p.first][tmp_p.second+1] = true;
      q.push(tmpp_p);
    }


  }

  cout << number[gy][gx] << endl;
  
  return 0;
}
