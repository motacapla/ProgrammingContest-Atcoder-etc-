template <typename T>
struct UnionFind {
	T n;
	vector<T>d;
	UnionFind() {}
	UnionFind(T n) :n(n), d(n, -1) {}
 
	int root(T x) {
		if (d[x] < 0) return x;
		return d[x] = root(d[x]);
	}
	bool unite(T x,T y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (size(x) < size(y)) swap(x, y); 
		d[x] += d[y];
		d[y] = x;
		return true;
	}
	int size(T v) { return -d[root(v)]; }
};
