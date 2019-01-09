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

map<int, int> mp;

void bunkai(int val){
  int i = 2;
  while(val >= i * i){
    if(val%i == 0){
      val /= i;
      mp[i]++;
    }
    else{
      i++;
    }
  }
  mp[val]++;
}

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n;
  int ans2=0, ans4=0, mid=0;
  cin >> n;
  
  REP(i, n) {
    int tmp;
    mp.clear();
    cin >> tmp;
    bunkai(tmp);
    if(mp[2] > 1) ans4++;
    else if(mp[2] > 0) ans2++;
  }

  //cout << ans2 << " " << ans4 << endl;
  
  if(n/2 <= ans4 || n <= ans2 || n/2 <= ans4+(ans2/2)) cout << "Yes" << endl;
  else cout << "No" << endl;
  /*
    n = 2:
    ans4 = 1 or ans2 = 2
    n = 3:
    ans4 = 1 or ans2 = 3
    n = 4:
    ans4 = 2 or ans4 = 1 ans2 = 2 or ans2 = 4
    n = 5:
    ans4 = 2 or ans4 = 1 ans2 = 2 or ans2 = 5
   */
  
  return 0;
}
