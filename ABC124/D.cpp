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

template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}
int v0_i, v1_i;

//解説AC
//http://drken1215.hatenablog.com/entry/2019/04/14/222900
//まぜこぜ累積和がかけなかった...

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n,k;
  string s;
  cin >> n >> k;
  cin >> s;
  
  vector<int> nums;    
  if (s[0] == '0') nums.push_back(0);
  for (int i = 0; i < s.size();) {
    int j = i;
    while (j < s.size() && s[j] == s[i]) ++j;
    nums.push_back(j - i);
    i = j;
  }
  if (s.back() == '0') nums.push_back(0);

  vector<int> sums((int)nums.size() + 1, 0);
  for (int i = 0; i < nums.size(); ++i) sums[i+1] = sums[i] + nums[i];

  for(auto &e : sums) cerr << e << " ";
  cerr << endl;
  
  int ans = 0;
  for(int l = 0; l < sums.size(); l+=2){
    int r = l+k*2+1;
    if(r >= sums.size()) r = sums.size()-1;
    ans = max(ans, sums[r]-sums[l]);
  }
  cout << ans << endl;
  return 0;
}
