/*
  UnionFind<int> uf = UnionFind<int>(n+1); //nだとREでるの謎い..
  REP(i, m) uf.unite(x[i], y[i]);
*/
template <typename T>
class UnionFind {
public:
  T n;
  vector <T> d;
  UnionFind(T n) :d(n, -1) {} 
  int find(T x){
    if(d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(T x, T y){
    x = find(x);
    y = find(y);
    if(x == y) return false;
    if(d[y] < d[x]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  int size(T x){ return -d[find(x)];}
  bool same(T x, T y){
    return find(x) == find(y);
  }
};
