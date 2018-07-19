#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, n, m) for(int i = n; i < (int)(m); i++)
#define REPLL(i, n, m) for(long long i = n; i < (long long)(m); i++)
#define SORT(v, n) sort(v, v+n);

using namespace std;
using ll = long long;

int
main(void){

  /*
unordered_map | map
ハッシュテーブル |二分木（通常は赤黒木）
O(1) | O(log N)
Pros:高速 | キーが順序付け
Cons:順序バラバラ | 遅い
   */
  
  unordered_map<string, int> mp;
  mp["hoge"] = 123;

  unordered_map<string, int> mp2(mp); //copy
  
  mp2["huga"] = 456;

  cout << mp["hoge"] << " " << mp2["huga"]  << " " << mp2["hoge"]<< endl;

  cout << "mp2 size:" << mp2.size() << endl;
  
  mp2.erase("hoge");

  cout << "mp2 size:" << mp2.size() << endl;
  
  
  return 0;
}
