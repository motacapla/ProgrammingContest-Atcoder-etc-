#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

int
main(void){
  int n, m;
  cin >> n >> m;
  ll x, y;
  cin >> x >> y;
  ll a[n], b[m];

  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<m; i++) cin >> b[i];

  ll current;
  int count, max=0;
  int xj, yj = 0;

  count = 0;  
  current = a[0];
  while(xj < n){
    for(int i=yj; i<m; i++){
      if(current + x <= b[i]){
	current = b[i];
	count++;	  
	break;
      }
      yj++;    
    }
    
    for(int j=xj; j<n; j++){
      if(current + y <= a[j]){
	current = a[j];
	break;
      }
      xj++;
    }
  }

  cout << count << endl;
  return 0;
}
