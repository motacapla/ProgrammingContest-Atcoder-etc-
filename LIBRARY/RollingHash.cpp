#include <bits/stdc++.h>
/*
RollingHash
construct: O(n)
      get: O(1)
  connect: O(1)
      LCP: O(logn)
 */

struct RollingHash {
  typedef unsigned long long ull;
  string S;
  ull B;
  int len;
  vector<ull> hash, p;
  RollingHash() {}
  RollingHash(string S_, ull B_=1e9LL) :
    S(S_), B(B_), len(S.length()), hash(len+1), p(len+1){
    hash[0] = 0; p[0] = 1;
    REP(i, len){
      hash[i+1] = hash[i]*B + S[i];
      p[i+1] = p[i]*B;
    }
  }
  ull find(int l, int r){
    return hash[r]-hash[l]*p[r-l];
  }
};

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string a,b;
  cin >> a >> b;
  RollingHash A(a), B(b);
  for(int i=0; i+b.size() <= a.size(); i++)
    if(A.find(i, i+b.size()) == B.find(0, b.size()))
      cout << i << endl;
  
  return 0;
}
