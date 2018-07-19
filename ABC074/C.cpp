#include <iostream>
#include <set>
#include <algorithm>

#define REP(i,m,n) for(int i=int(m);i<int(n);i++)
#define EACH(i,c) for (auto &(i): c)
#define SORT(c) sort(begin(c),end(c))


using namespace std;
using ll = long long;

double dense(int a, int b){
  return 100*b/(a+b);
}

int
main(void){
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  ll sums = 0L;

  bool dp[3001][3001] = {};
  dp[0][0] = true;
  for(int i=0; i<3000; i++){
    for(int j=0; j<3000; j++){
      if(dp[i][j] == false) continue;
      if(i+j+100*a <= f) dp[i+100*a][j] = true;
      if(i+j+100*b <= f) dp[i+100*b][j] = true;
      if(i+j+c <= f) dp[i][j+c] = true;
      if(i+j+d <= f) dp[i][j+d] = true;
    }
  }

  double ans = 0;
  int w = 0, s = 0;
  for(int i=0; i<3000; i++){
    for(int j=0; j<3000; j++){  
      if (dp[i][j] == false) continue;
      if (i + j > f) continue;
      if(i * e < j * 100) continue;
      if(ans <= 100.0 * j / (i+j)){
	ans = 100.0 * j / (i+j);
	w = i;
	s = j;
      }
    }
  }

  cout << w + s << " " << s << endl;
  
  return 0;
}
