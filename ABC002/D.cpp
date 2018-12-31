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

int x[1000], y[1000];
int relations[1000][1000];

int
main(void){  
  ios_base::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  if(m == 0) { cout << 1 << endl; return 0;}
  
  REP(i, n) REP(j, n) relations[i][j] = false;

  REP(i, m) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
    relations[x[i]][y[i]]++;
    relations[x[i]][x[i]]++;
    relations[y[i]][y[i]]++;    
    relations[y[i]][x[i]]++;
  }
  
  int ans = 0;  
  for(int bit = 0; bit < (1<<n); ++bit){

    //bitの数を数えられる
    //ll num = __builtin_popcount(bit);
    
    vector<int> v;
    REP(i, n){
      //{0, ..., 0}から{1, ..., 1}まで
      if(((bit >> i)&1) == 1) v.push_back(i);
      //{0, ..., 0}から{0, ..., n}まで
      //if((bit & (1 << i)) == 1) v.push_back(i);
    }
    
    bool ok = true;    
    REP(i, (int)v.size()){
      REP(j, (int)v.size()){
	if(relations[v[i]][v[j]] == 0) ok = false;	
      }
    }
    if(ok) ans = max(ans, (int)v.size());
  }

  cout << ans << "\n";
  
  return 0;
}

  /*
  //memset(d, -1, sizeof(d));
  fill(d.begin(), d.end(), -1);
  
  REP(i, m) unite(x[i], y[i]);

  //REP(i, m) cout << size(i+1) << endl;
  ll ans = 0;
  REP(i, m) {if(ans < size(i+1)) ans = size(i+1);}
  */
