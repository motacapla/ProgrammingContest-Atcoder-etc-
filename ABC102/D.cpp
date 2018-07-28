#include <iostream>

using namespace std;
using ll = long long;


int get_idx(ll sall[], ll sum, int begin, int end){
  ll m = abs(sall[begin]-sum+sall[begin]);
  int mi = 0;
  ll ltmp = 0LL;
  for(int i=begin+1; i<end; i++){
    ltmp = abs(sall[i]-sum+sall[i]);
    cout << "Left Region: " << sall[i] << endl;
    cout << "Right Region: " << (sum-sall[i]) << endl;
    cout << "ABS: " << ltmp << endl;    
    if(ltmp < m){
      m = ltmp;
      mi = i;
    }
  }
  return mi;
}


int main(void){
  int n;
  cin >> n;
  
  ll a[n];
  ll sall[n];
  for(int i=0; i<n; i++){
    cin >> a[i];
    sall[i] = 0LL;
  }

  //累積和
  sall[0] = a[0];  
  for(int i=1; i<n; i++) sall[i] = sall[i-1] + a[i];
  //for(int i=0; i<n; i++) cout << sall[i] << endl;

  //MAX
  ll sum = sall[n-1];

  //1. 二分割  
  int m2 = get_idx(sall, sum, 0, n);
  int m1 = get_idx(sall, sum, 0, m2);
  int m3 = get_idx(sall, sum, m2, n);

  cout << m1 << m2 << m3 << endl;
  
  //↑を2回やればとけるくね?  
  /*
  //尺取法
  for(int left=0; left<n; left++){
    int right = left;
    while(right != n){
      cout << "L: " << left << "R: " << right << endl; 
      right++;
    }
  }
  */
  
  return 0;
}
