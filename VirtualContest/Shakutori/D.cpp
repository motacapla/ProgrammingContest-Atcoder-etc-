#include <bits/stdc++.h>

//https://yang33-kassa.jp/diary/201904-1/

long long dp[110000];
const long long MOD = 1e9+7;

int main(void){  
  long long n, m;
  std::cin >> n >> m;
  std::vector<long long> v(n);
  for(int i=0; i<n; i++) std::cin >> v[i];

  long long sum = 1LL;
  dp[0] = 1;
  std::map<long long, long long> mp;
  for(int left = 0, right = 0; right < n; right++) {
    mp[v[right]]++;
    while(mp[v[right]] > 1) {
      sum = (sum - dp[left] + MOD)%MOD;
      mp[v[left]]--;
      left++;
    }
    dp[right+1] = sum;
    sum += dp[right+1];
    sum %= MOD;
  }
  std::cout << dp[n] << std::endl;

  return 0;
}
