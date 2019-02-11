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
#include <iostream>
#include <fstream>

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

//a[x][y], x, y
typedef std::tuple<int, int, int> mytuple;
//https://minus9d.hatenablog.com/entry/2014/07/05/215756
bool mycompare( const mytuple &lhs, const mytuple &rhs )
{
    if (std::get<0>(lhs) != std::get<0>(rhs)) return std::get<0>(lhs) < std::get<0>(rhs);
    if (std::get<1>(lhs) != std::get<1>(rhs)) return std::get<1>(lhs) < std::get<1>(rhs);
    return std::get<2>(lhs) < std::get<2>(rhs);
}
vector<mytuple> v;

const string filename_i = "intput.txt";
const string filename_o = "output.txt";
const int INF = 1e9;
int a[51][51];
//https://stackoverflow.com/questions/5712172/how-can-i-store-3-integer-in-priority-queue
struct S
{
    int m_n1;
    int m_n2;
    int m_n3;

    S(int n1, int n2, int n3) : m_n1(n1), m_n2(n2), m_n3(n3)
    {
    }

    bool operator<(const struct S& other) const
    {
        //Your priority logic goes here
        return m_n1 < other.m_n1;
    }
};

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n=0, m=0, minimum=INF;
  string s;
  priority_queue<mytuple, vector<mytuple>, greater<mytuple>> q;
  
  cin >> n >> m;
  REP(i, n) REP(j, n){
    cin >> a[i][j];
    q.push(make_tuple(a[i][j], i, j));
  }
  ofstream ofs(filename_o);
   
  int harv = 25*25;
  int grew = m-harv;
  
  while (grew > 0) {
    mytuple t = q.top(); q.pop();
    int x = get<1>(t), y = get<2>(t);    
    q.push(make_tuple(a[x][y]+1, x, y));
    //ofs << "1 " << x << " " << y << endl;
    cout << "1 " << x << " " << y << endl;    
    grew--;
  }

  //grew
  int eo = 0;
  for(int i=0; i<n; i+=2){
    for(int j=eo; j<n; j+=2){
      //ofs << "2 " << i << " " << j << endl;
      cout << "2 " << i << " " << j << endl;      
    }
    if(eo == 0) eo = 1;
    else eo = 0;
  }
  
  ofs.close();
  
  return 0;
}
