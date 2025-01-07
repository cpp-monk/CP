int get(int a, vector<int>& component) {
	return component[a] = (component[a] == a ? a : get(component[a], component));
}
void merge(int a, int b, vector<int>& rank, vector<int>& component) {
	a = get(a, component);
	b = get(b, component);
	if (a == b)
		return;
	if (rank[a] == rank[b])
		rank[a]++;
	if (rank[a] > rank[b])
		component[b] = a;
	else
		component[a] = b;
}

void solve() {

	int n, m;
	cin >> n >> m;
	vector<int> component(n);
	for (int i = 0; i < n; i++) {
		component[i] = i;
	}
	vector<int> rank(n, 0);
	vector<pair<ll, pair<int, int>>> edges;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({c, {a, b}});
	}
	sort(edges.begin(), edges.end());
	vector<pair<pair<int, int>, ll>> ans;
	for (auto i : edges) {
		if (sz(ans) == n - 1)
			break;
		int a = i.ss.ff;
		int b = i.ss.ss;
		if (get(a, component) != get(b, component)) {
			merge(a, b, rank, component);
			ans.push_back({{min(a, b), max(b, a)}, i.ff});
		}
	}
	for (auto i : ans) {
		cout << i.ff.ff << " " << i.ff.ss << " " << i.ss << endl;
	}
}
