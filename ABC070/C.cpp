#include <iostream>
#include <numeric>
#include <algorithm>

long long lcm(long long a, long long b)
{
  return (b==0) ? a:  a / std::__gcd(a,b) * b;
}

int main(int argc, char* argv[]){
  int N;  
  std::cin >> N;
  
  long long temp, answer=1LL;
  for(int i=0; i<N; i++){
    std::cin >> temp;
    answer = lcm(answer, temp);
  }  
  std::cout << answer << std::endl;
  
  return 0;
}
