#include <bits/stdc++.h>
#define ll long long

std::map<ll, ll> mp;

int main(void){  
  ll n;
  std::cin >> n;
  std::vector<ll> a(n);
  for(int i=0; i<n; i++) std::cin >> a[i];

  ll ans = 0LL;
  int right = 0;
  for(int left=0; left<n; left++) {
    for(;;) {
      if(right == n || mp[a[right]] > 0) break;
      mp[a[right]]++;
      right++;
    }
    ans = std::max(ans, (ll)right-left);
    if(right == n) break;
    mp[a[left]]--;
    if(left == right) right++;
  }
  std::cout << ans << std::endl;
  return 0;
}
