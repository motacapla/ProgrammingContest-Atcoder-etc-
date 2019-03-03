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

class Solution {
public:
  vector<string> commonChars(vector<string>& A) {        
    std::map<char, int> mp[A.size()];
    std::map<char, int> allstr;
    for(int i=0; i<A.size(); i++){
      for(int j=0; j<A[i].size(); j++){
	mp[i][A[i][j]]++;
	allstr[A[i][j]]++;
      }
    }
    vector<string> ans;        
    for(auto j=allstr.begin(); j != allstr.end(); j++){
      int sum = mp[0][j->first];                
      int min_v = 1e9/2;
      for(int k=0; k < A.size(); k++){
	min_v = min(min_v, mp[k][j->first]);
      }
      string t = "";
      t += j->first;
                
      for(int i=0; i<min_v; i++) ans.push_back(t);   
                
      //std::cout << j->first << " " << j->second << " sum " << sum << " min_v " << min_v << std::endl;
            
    }
    return ans;
  }
};

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);


  
  
  return 0;
}
