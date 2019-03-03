https://qiita.com/drken/items/ecd1a472d3a0e7db8dce
/* Q 回分のクエリを処理 */
for (int j = 0; j < Q; ++j) {
  long long x; cin >> x; // 各クエリ x

  /* 合計値 */
  long long res = 0;

  /* 区間の左端 left で場合分け */
  int right = 0;     // 毎回 right を使い回すようにする
  long long sum = 0; // sum も使い回す
  for (int left = 0; left < n; ++left) {
    /* sum に a[right] を加えても大丈夫なら right を動かす */
    while (right < n && sum + a[right] <= x) {
      sum += a[right];
      ++right;
    }

    /* break した状態で right は条件を満たす最大 */
    res += (right - left);

    /* left をインクリメントする準備 */
    if (right == left) ++right; // right が left に重なったら right も動かす
    else sum -= a[left]; // left のみがインクリメントされるので sum から a[left] を引く
  }

  cout << res << endl;
