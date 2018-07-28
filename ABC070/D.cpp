#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using ll = long long;
const int limit = 100010;
using edge = struct {int to; ll cost;};
vector<edge> tree[limit];
ll depth[limit];

void BFS(int v){
  queue<int> q;
  int i=0;
  visited[v] = 1;
  q.push(v);
  while(q.size()!=0){
    v = q.front();
    q.pop();
    int d=0;
    while(tree[v].next != 0){
      i = tree[v].next;
      d += tree[v].val;
      visited[i] = 1;
      best_dst[i] = d;
      q.push(i);
    }
  }
}

int main(int argc, char* argv[]){  
  int n;
  cin >> n;

 for (int i = 0; i < n - 1; ++i) {
   int a, b, c;
   cin >> a >> b >> c;
   a--, b--;
   tree[a].push_back({b, c});
   tree[b].push_back({a, c});
 }
  /*
  for(int i=0; i<N; i++){
    visited[i] = 0;
  }

  for(int i=0; i<N; i++){
    cout << i << " : " << tree[i].next << endl;
  }
  cin >> Q >> K;

  BFS(K-1);
  
  for(int i=0; i<Q; i++){
    cin >> x >> y;
    //cout << best_dst[x-1] + best_dst[y-1] << endl;
  }

  for(int i=0; i<N; i++){
    cout << i << ":" << best_dst[i] << endl;
  }
  */
  return 0;
}

  


