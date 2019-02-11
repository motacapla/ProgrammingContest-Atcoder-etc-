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

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
    if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}
//解説AC いもす法,
//https://atcoder.jp/contests/abc001/submissions/4131734

int
main(void){
  int n,a,b;
  cin >> n;
  string s;
  vector<int> imos(500,0);
  //アメふってる時間に++してから、いもす法でパッと計算
  REP(i,n){
    cin >> s;
    a=stoi(s.substr(0,4));
    b=stoi(s.substr(5,4));
    b+=4;
    if(b%100>=60)b+=40;
    imos[a/5]++;imos[b/5]--;
  }
  int begin=0, end;
  FOR(i, 1, (2400/5)+1){
    imos[i]+=imos[i-1];
    //true(> 0)が始まったら(つまり左端) begin
    if(imos[i-1]<=0 && imos[i]>0){
      begin=i;
    }
    //true->falseになる(つまり右端) end
    else if(imos[i-1]>0 && imos[i]<=0){
      begin=begin*5;
      end=i*5;
      if(begin%100==60)begin+=100-60;
      if(end%100==60)end+=100-60;
      printf("%04d-%04d\n",begin,end);
    }    
  }
}

/*
int S[30010], E[30010];

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  REP(i, n){
    vector<string> vs;
    string str;
    cin >> str;
    vs = split(str, '-');
    S[i] = stoi(vs[0]);
    E[i] = stoi(vs[1]);
    if(S[i]%10 < 5) S[i] = S[i] - (S[i]%10);
    else if(S[i]%10 <= 9) S[i] = S[i] - (S[i]%10) + 5;

    if(E[i]%10 == 0) continue;
    else if(E[i]%10 <= 5) E[i] = E[i] - (E[i]%10) + 5;
    else if(E[i]%10 <= 9) E[i] = E[i] - (E[i]%10) + 10;
  }

  sort(S, S+n);
  sort(E, E+n);

  vector<P> lr;
  lr.push_back(make_pair(S[0],E[0]));

  FOR(i,1,n){
    bool f = true;
    int tmp_l, tmp_r;
    tmp_l = S[i]; tmp_r = E[i];
    int ii=0;
    for(auto itr=lr.begin(); itr!=lr.end(); ++itr){      
      //cout << "i:" << i << " l: " << itr->first << " r: " << itr->second << endl;
      //cout << "i:" << i << " tmp_l: " << tmp_l << " tmp_r: " << tmp_r << endl;      
      int l = itr->first, r = itr->second;
      if(l>tmp_r || r<tmp_l) {
	lr.push_back(make_pair(tmp_l,tmp_r));
	break;
      }
      if(tmp_l<l && r<tmp_r){
	lr.erase(lr.begin()+ii, lr.begin()+ii+1);
	lr.push_back(make_pair(tmp_l,tmp_r));
	break;
      }
      
      if(l<=tmp_r && tmp_l<=l){
	lr.erase(lr.begin()+ii, lr.begin()+ii+1);
	lr.push_back(make_pair(tmp_l,r));
	break;
      }
      if(r>=tmp_l && tmp_r>=r){
	lr.erase(lr.begin()+ii, lr.begin()+ii+1);
	lr.push_back(make_pair(l,tmp_r));
	break;
      }
      ii++;
    }
    
  }

  for(auto itr=lr.begin(); itr!=lr.end(); ++itr){
    string l = to_string(itr->first);
    while(l.size() < 4) l = '0'+l;    
    string r = to_string(itr->second);
    while(r.size() < 4) r = '0'+r;    
    cout << l << "-" << r << endl;
  }
  
  return 0;
}
*/

