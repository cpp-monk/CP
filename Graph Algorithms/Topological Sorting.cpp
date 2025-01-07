void dfs(int start, vector<int>*edges, bool *visited, vector<int>& ans)
{
	visited[start] = true;
	for (auto i : edges[start])
	{
		if (visited[i])
			continue;
		dfs(i, edges, visited, ans);
	}
	ans.pb(start);
}
vector<int> topo_sort(int n, vector<int>*edges)
{
	vector<int> v1;
	bool *visited = new bool[n]();
	for (int i = 0; i < n; i++)
	{
		if (visited[i])
			continue;
		dfs(i, edges, visited, v1);
	}
	reverse(v1.begin(), v1.end());
	return v1;
}
int main()
{
	fastio();
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	freopen("Error.txt", "w", stderr);
#endif
	int n, m;
	cin >> n >> m;
	vector<int>*edges = new vector<int>[n];
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		edges[u].pb(v);
	}
	vector<int> v1 = topo_sort(n, edges);
	for (int i = 0; i < n; i++)
		cout << v1[i] + 1 << " ";
	cout << endl;
	return 0;
}
