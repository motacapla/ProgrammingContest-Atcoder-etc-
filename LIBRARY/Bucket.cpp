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
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define FORLL(i, n, m) for(long long i = n; i < (long long)(m); i++)
#define SORT(v, n) sort(v, v+n);
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


const ll sqrtN = 512;

vector<ll> data, bucket;
ll n, q, com, x, y, size;

void add(ll x, ll y) {
    ll k = x/sqrtN;
    data[x] += y;
    ll sum = 0;
    for (ll i=k*sqrtN; i<(k+1)*sqrtN; i++) {
      sum += data[i];
    }
    bucket[k] = sum;    
}
// [x, y)
int getSum(ll x, ll y) {
    ll sum = 0;
    for (ll k = 0; k < size; ++k) {
      ll l = k*sqrtN, r=(k+1)*sqrtN;
      if (r <= x || y <= l)
        continue;
      if (x <= l && r <= y) {
        sum += bucket[k];
      } else {
        for (ll i = max(x, l); i < min(y, r); ++i) {
          sum += data[i];
        }
      }
    }
    return sum;
}

int main(void){
    cin >> n >> q;
    // prepare arrays
    ll size = (n + sqrtN - 1) / sqrtN;
    data.assign(size*sqrtN, 0);
    bucket.assign(size, 0);

    REP(i, q) {
        cin >> com >> x >> y;
        if(com == 0) {
            add(x, y);
        } else {
            cout << getSum(x, y+1) << endl;
        }
    }

    return 0;
}