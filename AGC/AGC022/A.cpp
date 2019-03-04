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

template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

//解説AC
//https://atcoder.jp/contests/agc022/submissions/4432724

//1. string.empty()
//2. string.erase(one arg)
//3. 後ろから文字消して、まだ使ってない文字 && より後ろにある文字を埋める

int n=26;
int v[26];

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  string s, ans="";
  cin >> s;

  REP(i, s.size()) v[s[i]-'a']++;
  
  //REP(i, n) cout << v[i] << endl;  
  int tmp = 0, idx = 0;
  REP(i, n) if(v[i] == 1) tmp++;
  
  if(tmp == n){
    bool ok = false;
    while(!s.empty() && !ok){
      int back = s.back() - 'a';
      s.erase(s.end()-1);
      v[back] = 0;
      for(int i=back+1; i<n; i++){
	if(!v[i]){
	  s += i+'a';
	  ok = true;
	  break;
	}
      }
    }
    ans = s;
  }
  else{
    char moji;
    REP(i, n) if(v[i] != 1){moji='a'+i; break;}
    ans += s+moji;    
  }
  if(ans.empty()) cout << -1 << endl;
  else cout << ans << endl;
  
  
  return 0;
}


    /*
    REP(i, n) {
      if(s[i] == 'z') {
	idx = i;
	break;
      }
    }
    if(idx == 0){cout << -1 << endl; return 0;}
    else idx--;
    REP(i, idx){
      ans += s[i];
    }
    ans += s[idx]+1;
    */
