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
//https://atcoder.jp/contests/agc016/submissions/4386806
//実装力がほしい
//1. count(string.begin(), string.end(), word)で文字数を数えられる
//2. char word = char('a'+i);でアルファベット
//3. アルファベットで全探索

map<char, int> mp;
int n;

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  string s;
  int ans = 1e9/2;
  string max_s = "";
  cin >> s;
  n = s.size();

  REP(i, 26){
    char word = char('a'+i);
    int num=0;
    string tmp1=s, tmp2;
    while(count(tmp1.begin(), tmp1.end(), word) != tmp1.size()){
      tmp2 = tmp1;
      tmp1 = "";
      REP(i, tmp2.size()-1){
	if(tmp2[i] == word || tmp2[i+1] == word){
	  tmp1 += word;
	}
	else{
	  tmp1 += tmp2[i];
	}
      }
      num++;
    }
    ans = min(ans, num);
  }
  
  cout << ans << endl;

  
  return 0;
}
