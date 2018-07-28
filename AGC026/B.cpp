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



int main(void){
  int t;
  cin >> t;
  ll a[t], b[t], c[t], d[t];
  rep(i, t) cin >> a[i] >> b[i] >> c[i] >> d[i];

  rep(j, t){
    int f=0;
    ll limit = 0L;
    ll store = a[j];
    ll diff = d[j] - b[j];
    if(diff < 0) {PRINT("No"); continue;}
    if(a[j] - b[j] < 0) {PRINT("No"); continue;}
    if(c[j] >= b[j]) {PRINT("Yes"); continue;}
    ll g = __gcd(b[j],d[j]);
    ll m = b[j] - g + (a[j] % g);
    if (m > c[j]){
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }    
    /*
    rep(i, 50000){   
      //if(store / b[j] <= 0) {PRINT("No"); f=1; break;}
      store = store % b[j];
      //if(store < 0) {PRINT("No"); f=1; break;}
      if(store <= c[j]) store = store + d[j]; 
      //在庫がb未満
      if(store < b[j]) {PRINT("No"); f=1; break;}         
    }
    if(!f) PRINT("Yes");
    */
  }


  
  return 0;
}
