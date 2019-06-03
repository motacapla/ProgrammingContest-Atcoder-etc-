//問題: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1280
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
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define FORLL(i, n, m) for(long long i = n; i < (long long)(m); i++)
#define SORT(v, n) sort(v, v+n);
#define REVERSE(v) reverse((v).begin(), (v).end())

using namespace std;
using ll = long long;
const ll MOD=1000000007LL;
ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

/* Prim法 */
// P : (cst, to)
// https://algoogle.hadrori.jp/algorithm/prim.html
#define MAX 10000000
using pii = pair<int, int>;
vector<pii> G[MAX];
bool used[MAX];
int prim(void){
    priority_queue <pii, vector<pii>, greater<pii>> q;
    memset(used, 0, sizeof(used));
    q.push({0, 0}); //初期値
    int ans = 0;
    while(!q.empty()){
        int cost = q.top().first; 
        int to = q.top().second;
        q.pop();
        if(used[to]) continue;
        cerr << "to:" << to+1 << endl;
        int ret = MAX;
        used[to] = true;
        ans += cost;
        REP(i, G[to].size()){
            q.push({G[to][i].first, G[to][i].second});
        }
    }
    return ans;
}

int main(void){
    int n, m;
    cin >> n >> m;
    REP(i, m) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        G[a].push_back({w, b});   
    }

    int ans = prim();

    cout << ans << endl;
}
