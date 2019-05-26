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

int n, m;
int k[12];
int s[12][12];
int t[12][12];
int p[12];

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  REP(i, m){
    cin >> k[i];
    REP(j, k[i]) {
      int val;
      cin >> val;
      val--;
      s[i][val]++;
    }
  }
  REP(i, m) cin >> p[i];
  /*
  REP(i, m){
    REP(j, n){      
      cerr << s[i][j] << " ";
    }
    cerr << endl;
  }  
  */
  int ans = 0;
  REP(bit, (1<<n)){
    cerr << bitset<10>(bit) << endl;
    memset(t, 0, sizeof(t));    
    REP(j, n){
      if(bit & (1<<j)){
	REP(i, m){
	  t[i][j]++;
	}
      }
    }
    /*
    REP(j, n){
      REP(i, m){
        cerr << t[i][j] << " ";
      }
      cerr << endl;
    }
    */
    int cnt = 0;
    REP(i, m){
      int sum = 0;
      REP(itr, n) {
	//cerr << s[i][itr] << "vs" << t[i][itr] << endl;
	if(t[i][itr] && s[i][itr]) sum++;
      }
      if((sum)%2 == p[i]) cnt++;            
    }
    cerr << "cnt:" << cnt << endl;
    if(cnt == m) ans++;
  }
  cout << ans << endl;
  
  return 0;
}
