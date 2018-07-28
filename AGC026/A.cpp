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

int main(int argc, char* argv[]){
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  int prev_val, count=0;
  REP(i, 1, n) {
    prev_val = a[i-1];
    if(a[i] == prev_val){
      //cout << "i:" << i << endl;
      if(i < n-1 && a[i+1] != i+1){
	a[i] = i+1;
      }else{
	a[i] = 10000-i;
      }
      count++;
    }
  }
  /*
  rep(i, n) cout << a[i] << " ";
  cout << endl;
  */
  
  PRINT(count);
  
  return 0;
}
