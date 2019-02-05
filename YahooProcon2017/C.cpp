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

int a[100100];
string s[100100];

vector<int> num;
map<string, int> mp;

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  REP(i, k) {
    int x;
    cin >> x;
    a[--x]++;
  }
  string t, ans;
  REP(i, n){
    cin >> s[i];
    if(a[i]) t = s[i];
  }
  //tはなんでもよい?
  int m = -1;
  REP(i, n){
    //a[i]に含まれるのは無視
    if(a[i]) continue;
    int tmp = 0;
    //a[i]に含まれていない文字の上から最大長を探す
    REP(j, min((int)t.length(), (int)s[i].length())){
      if(t[j] != s[i][j]) break;
      tmp++;
    }
    m = max(tmp, m);
  }

  //最大長 = aの文字
  if(m == (int)t.length()){
    cout << -1 << endl;
    return 0;
  }

  //結局ここで間引く
  ans = t.substr(0, m+1);
  
  REP(i, n){
    if(!a[i]) continue;
    if(ans != s[i].substr(0, m+1)){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
  
  return 0;
}
