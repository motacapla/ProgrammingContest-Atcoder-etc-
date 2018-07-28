#include<iostream>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<array>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<cassert>
#include<functional>
#include<random>
#include<complex>
#include<bitset>
#include<chrono>
#define REP(i, a, b) for (int64_t i = (int64_t)(a); i < (int64_t)(b); i++)
#define rep(i, a) REP(i, 0, a)
#define PRINT(x) std::cout << x << std::endl
#define EACH(i, a) for (auto i: a)
#define ITR(x, a) for (auto x = a.begin(); x != a.end(); x++)
#define ALL(a) (a.begin()), (a.end())
#define HAS(a, x) (a.find(x) != a.end())
#define Min(x) *min_element(ALL(x))
#define Max(x) *max_element(ALL(x))
#define Unique(L) (L.erase(unique(ALL(L)), L.end()))
#define veccat(v1, v2) std::copy((v2).begin(),(v2).end(),std::back_inserter(v1)/*v1の後ろにv2を入れる*/)
#define intmax (std::numeric_limits<int64_t>::max() / 4)
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const double MOD = 1e9+7;

using ll = long long;

uintmax_t combination(unsigned int n, unsigned int r) {
  if ( r * 2 > n ) r = n - r;
  uintmax_t dividend = 1;
  uintmax_t divisor  = 1;
  for ( unsigned int i = 1; i <= r; ++i ) {
    dividend *= (n-i+1);
    divisor  *= i;
  }
  return dividend / divisor;
}


int main(void){
  int n;
  cin >> n;
  string s;
  cin >> s;

  ll count = 0L;

  //count = count + combination(8, 4);
  count = count + combination(2, 1);
  count = count + combination(2, 1);
  count = count + combination(2, 1);
  count = count + combination(2, 1);
  count = count + combination(2, 1);
  //count = count + combination(6, 3);
  
  PRINT(count*2);
  
  return 0;
}
