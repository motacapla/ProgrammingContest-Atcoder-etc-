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

map<string, int> mp;

string Do = "WBWBWWBWBWBW";
string Re = "WBWWBWBWBWWB";
string Mi = "WWBWBWBWWBWB";
string Fa = "WBWBWBWWBWBW";
string So = "WBWBWWBWBWWB";
string La = "WBWWBWBWWBWB";
string Si = "WWBWBWWBWBWB";

int
main(void){  
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;  
  
  REP(i, 12){
    if(s[i] != Do[i]) mp["Do"]++;
    if(s[i] != Re[i]) mp["Re"]++;
    if(s[i] != Mi[i]) mp["Mi"]++;
    if(s[i] != Fa[i]) mp["Fa"]++;
    if(s[i] != So[i]) mp["So"]++;
    if(s[i] != La[i]) mp["La"]++;
    if(s[i] != Si[i]) mp["Si"]++;    
  }

  if(!mp["Do"]) cout << "Do" << endl;
  if(!mp["Re"]) cout << "Re" << endl;
  if(!mp["Mi"]) cout << "Mi" << endl;
  if(!mp["Fa"]) cout << "Fa" << endl;
  if(!mp["So"]) cout << "So" << endl;
  if(!mp["La"]) cout << "La" << endl;
  if(!mp["Si"]) cout << "Si" << endl;
  
  return 0;
}
