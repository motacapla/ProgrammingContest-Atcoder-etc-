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

using namespace std;
using ll = long long;
const ll MOD=1000000007LL;
typedef pair<int, int> P;

#define INF (1<<29) //53687091
#define INFLL (1ll<<58)

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define ROF(i, j, k) for(int i = (int)(j); i >= (int)(k); --i)
#define FORLL(i, n, m) for(long long i = n; i < (long long)(m); i++)
#define SORT(v, n) sort(v, v+n)
#define REVERSE(v) reverse((v).begin(), (v).end())
#define DBG(x) cerr << #x << ": " << x << "\n";


ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }


int
main(void){  
  ll d, g;
  cin >> d >> g;

  int p[d];
  ll c[d];

  REP(i, d) {
    cin >> p[i] >> c[i];
  }

  bool f=false;
  int ans=0;
  ll sum = 0;
  ROF(i, d-1, 0){
    f = false;
    while(p[i]>0){
      sum += (i+1)*100;
      ans++;
      p[i]--;
      if(sum == g){
	f=true;
	break;
      }
      else if(sum > g) {
	sum -= (i+1)*100;
	ans--;
	p[i]++;
	break;
      }
    }
    if(sum == g || f){      
      break;
    }    
    if(p[i] == 0){
      sum += c[i];
    }
  }


  /*
  ll sum = g;
  ll ans = 0LL;
  ROF(i, d-1, 0){
    //cout << "Currenc sum: " << sum << endl;
    if(sum > p[i] * (i+1) * 100 + c[i]){
      sum -= p[i] * (i+1) * 100 + c[i];
      ans += p[i];
    }
    else{
      ll count = p[i];
      for(;;){
	if(count < 0) break;	
	sum -= (i+1) *100;
	if(sum < 0) break;
	++ans;
	--count;
	//cout << "While sum: " << sum << " count: " << count << endl;	
      }      
    }
  }
  

  int ans = INF, max_rest = 0;
  for(int mask=0; mask<(1<<d); mask++){
    int num=0, score=0;
    REP(i, d){
      if((mask>>i) & 1){
	num += p[i];
	score += p[i]*(i+1)*100 + c[i];
      }
      else{
	max_rest = i;
      }
    }
    //cout << mask << " : " << max_rest << " score: "<< score << " num: " << num <<  endl;
    if(score < g){
      int itmp = (max_rest+1)*100;
      int need = (g - score + itmp - 100) / itmp;
      //needが多すぎると, その単一のpだけでまかないきれないからやめる.
      if(p[max_rest] <= need) continue;
      //cout << "need:" << need << " p:" << p[max_rest]<<  endl;
      num += need;
    }
    ans = min(ans, num);
  }
*/
  cout << ans << endl;
  
  return 0;
}
