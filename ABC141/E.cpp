#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <numeric>
#include <cassert>
#ifdef DEBUG
#include "./Lib/debug.hpp"
#else
#define dump(...)
template<class T>inline auto d_val(T a, T b) { return a; }
#endif

/* (=＾o＾=) */
#define int ll

/* macro */
#define FOR(i, b, e) for(ll i = (ll)(b); i < (ll)(e); ++i)
#define RFOR(i, b, e) for(ll i = (ll)(e-1); i >= (ll)(b); --i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define REPC(x,c) for(const auto& x:(c))
#define REPI2(it,b,e) for(auto it = (b); it != (e); ++it)
#define REPI(it,c) REPI2(it, (c).begin(), (c).end())
#define RREPI(it,c) REPI2(it, (c).rbegin(), (c).rend())
#define REPI_ERACE2(it, b, e) for(auto it = (b); it != (e);)
#define REPI_ERACE(it, c) REPI_ERACE2(it, (c).begin(), (c).end())
#define ALL(x) (x).begin(),(x).end()
#define cauto const auto&
/* macro func */
#define SORT(x) do{sort(ALL(x));}while(false)
#define RSORT(x) do{sort((x).rbegin(),(x).rend());}while(false)
#define UNIQUE(v) do{v.erase( unique(v.begin(), v.end()), v.end() );}while(false)
#define MAX(x,y) do{x = std::max(x,y);}while(false)
#define MIN(x,y) do{x = std::min(x,y);}while(false)
#define BR do{cout<<"\n";}while(false)

/* type define */
using ll = long long;
using PAIR = std::pair<ll, ll>;
using VS = std::vector<std::string>;
using VL = std::vector<long long>;
using VVL = std::vector<VL>;
using VVVL = std::vector<VVL>;
using VD = std::vector<double>;
template<class T>
using V = std::vector<T>;

/* using std */
using std::cout;
constexpr char endl = '\n';
using std::cin;
using std::sort;
using std::pair;
using std::string;
using std::stack;
using std::queue;
using std::vector;
using std::list;
using std::map;
using std::unordered_map;
using std::multimap;
using std::unordered_multimap;
using std::set;
using std::unordered_set;
using std::unordered_multiset;
using std::multiset;
using std::bitset;
using std::priority_queue;

/* constant value */
constexpr ll MOD = 1000000007;
//constexpr ll MOD = 998244353;

/* Initial processing  */
struct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; }_Preprocessing;

/* Remove the source of the bug */
signed pow(signed, signed) { assert(false); return -1; }

/* define hash */
namespace std { template <>	class hash<std::pair<ll, ll>> { public:	size_t operator()(const std::pair<ll, ll>& x) const { return hash<ll>()(1000000000 * x.first + x.second); } }; }

/* input */
template<class T> std::istream& operator >> (std::istream& is, vector<T>& vec) { for (T& x : vec) is >> x; return is; }

//=============================================================================================


const int MAX = 500000, MS = 2;
const long long mod[] = {999999937LL, 1000000007LL}, base = 9973;
struct rolling_hash {
	int n;
	vector<long long> hs[MS], pw[MS];
	rolling_hash() {}
	rolling_hash(const string& s) {
		n = s.size();
		for (int i = 0; i < MS; i++) {
			hs[i].assign(n + 1, 0);
			pw[i].assign(n + 1, 0);
			hs[i][0] = 0;
			pw[i][0] = 1;
			for (int j = 0; j < n; j++) {
				pw[i][j + 1] = pw[i][j] * base % mod[i];
				hs[i][j + 1] = (hs[i][j] * base + s[j]) % mod[i];
			}
		}
	}

	long long hash(int l, int r, int i) { return ((hs[i][r] - hs[i][l] * pw[i][r - l]) % mod[i] + mod[i]) % mod[i]; }

	bool match(int l1, int r1, int l2, int r2) {
		bool ret = 1;
		for (int i = 0; i < MS; i++) ret &= hash(l1, r1, i) == hash(l2, r2, i);
		return ret;
	}

	bool match(int l, int r, long long h[]) {
		bool ret = 1;
		for (int i = 0; i < MS; i++) ret &= hash(l, r, i) == h[i];
		return ret;
	}
};

struct rolling_hash64 {
	int n;
	vector<long long> hs, pw;
	rolling_hash64() {}
	rolling_hash64(const string& s) {
		n = s.size();
		hs.assign(n + 1, 0);
		pw.assign(n + 1, 0);
		pw[0] = 1;
		for (int i = 0; i < n; i++) {
			hs[i + 1] = hs[i] * base + s[i];
			pw[i + 1] = pw[i] * base;
		}
	}

	long long hash(int l, int r) { return hs[r] - hs[l] * pw[r - l]; }
	bool match(int l1, int r1, int l2, int r2) { return hash(l1, r1) == hash(l2, r2); }
};

signed main() {
	ll n;
	string s;
	cin >> n >> s;
	auto rh = rolling_hash(s);

	ll ok = n;
	ll ng = -1;
	while (ok-ng > 1) {
		ll mid = (ok+ng)/2;
		bool is_ok = false;

		unordered_map<ll, ll> mp;
		REP(i, n - mid + 1) {
			auto hs = rh.hash(i, i + mid, 0);
			if (mp.find(hs) == mp.end()) {
				mp.emplace(hs, i);
			} else {
				if (!rh.match(mp[hs], mp[hs] + mid, i, i + mid)) continue; 
				if (i >= mp[hs] + mid) { is_ok = true; break; }
			}
		}
		if (is_ok) ng = mid; 
    else ok = mid; 
	}
	cout << ng << endl;
}
