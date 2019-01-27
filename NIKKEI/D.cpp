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

/*
//https://algoogle.hadrori.jp/algorithm/prim.html
vector<int> prim(int root) {
    priority_queue<pii, vector<pii>, greater<pii> > que;
    memset(used, 0, sizeof(used));
    que.push(pii(0,root));
    vector<int> T;
    int ret = 0;
    while(!que.empty()) {
        int cst = que.top().first, v = que.top().second;
        que.pop();
	//cout << "cur: " << v << endl;
        if(used[v]) continue;
	T.push_back(v);
        used[v] = 1;
        ret += cst;
        for(int i = 0; i < G[v].size(); i++)
            que.push(pii(G[v][i].first, G[v][i].second));
    }
    return T;
}
*/

//https://atcoder.jp/contests/nikkei2019-qual/submissions/4111304
#define MAX 100010
int n, m;
vector<int> v[MAX];
vector<int> tpv;
bool used[MAX];
int par[MAX];

//t: root
void tp(int t){
  used[t] = 1;
  REP(i, v[t].size()){
    //u: t -> i
    int u = v[t][i];
    if(used[u] == 1) continue;
    tp(u);
  }
  tpv.push_back(t);
  return;
}

int
main(void){  
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  vector<bool> bb(n+1, true);  
  REP(i, n+m-1){
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    bb[b] = false;
  }
  //leaf -> root
  FOR(i, 1, n+1) if(bb[i]) tp(i);
  /*
  for(auto itr = tpv.begin(); itr!=tpv.end(); itr++){
    cout << *itr << " ";
  }
  cout << endl;
  */
  //root -> leaf
  reverse(tpv.begin(), tpv.end());
  //各要素の親を設定
  REP(i, n){
    int t = tpv[i];
    REP(j, v[t].size()){
      int s = v[t][j];
      par[s] = t;
    }
  }
  REP(i, n) cout << par[i+1] << endl;
  
  return 0;
}
