//解説AC
//https://atcoder.jp/contests/abc038/submissions/4664456

#include <bits/stdc++.h>
//#define int long long
 
using namespace std;
using LL = long long;
using P = pair<int, int>;
 
#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(),(x).end()
 
const int INF = (int)1e9;
const LL INFL = (LL)1e19;
const int MOD = 1e9 + 7;
 
signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
    
  int n;
  cin >> n;
  vector<P> a;
  REP(i, n){
    int w, h;
    cin >> w >> h;
    a.push_back(make_pair(w, h));
  }
  sort(all(a), [](auto a, auto b){ return a.first < b.first ? true : (a.first == b.first ? a.second > b.second : false); });
  //for(auto &e: a) cerr << e.first << " " << e.second << endl;
  vector<int> dp(n+5, INF);
  REP(i, n){
    *lower_bound(all(dp), a[i].second) = a[i].second;
  }   
  int ans = lower_bound(all(dp), INF) - dp.begin();
  cout << ans << endl;
}
