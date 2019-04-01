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

//解説AC
int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string s;
  cin >> n;
  vector<int> b(n), ans;
  REP(i, n) cin >> b[i];

  REP(i, n){
    if(i-b[i]+1 < 0){
      cout << -1 << endl;
      return 0;
    }
  }
  
  ROF(i, n-1, 0){
    ROF(j, i, 0){
      //除去可能ならば
      if(j+1 == b[j]){
	ans.push_back(b[j]);
	//j以降を左に詰める
	FOR(k, j, n-1) b[k] = b[k+1];
	break;
      }
    }
    //チェック
    REP(j, b.size()) cerr << b[j] << " ";
    cerr << endl;    
  }
  reverse(ans.begin(), ans.end());
  REP(i,n) cout << ans[i] << endl;
  
  return 0;
}

  /*
  REP(i, n){
    if(i-b[i]+1 < 0){
      cout << -1 << endl;
      return 0;
    }    
    if(b[i] != 1){
      int tmp = b[i];
      REP(j, tmp-1) b[i-j] = b[i-j-1];
      b[i-tmp+1] = tmp;
    }
    REP(j, n) cerr << b[j] << " ";
    cerr << endl;
  }
  
  ROF(i,n-1,0) cout << b[i] << endl;
  */
