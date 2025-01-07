bool compare1(pair<int, ll> p1, pair<int, ll> p2)
{
	return p1.ss > p2.ss;
}
int get_min_vertex(bool* visited, ll* weight, int n)
{
	//can be used if there is some problem with priority queue and the time complexity allowed is O(N^2)
	int ans = -1;
	ll min1 = 1e18 + 1;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i] && weight[i] < min1)
		{
			min1 = weight[i];
			ans = i;
		}
	}
	return ans;
}
void prims(vector<pair<int, ll>>* edges, int n)
{
	bool*visited = new bool[n]();
	int* parent = new int[n];
	ll*weight = new ll[n];
	for (int i = 0; i < n; i++)
		weight[i] = 1e18;
	parent[0] = -1;
	weight[0] = 0;
	priority_queue<pair<int, ll>, vector<pair<int, ll>>, function<bool(pair<int, ll>, pair<int, ll>)>> pq1(compare1);
	pq1.push(mp(0, ll(0)));
	for (int i = 0; i < n - 1; i++)
	{
		//get_min_vertex which is unvisited and has minimum weight
		//getting minimum vertex can be done in LogN using priority queue
		int minVertex = pq1.top().ff;
		pq1.pop();
		while (visited[minVertex])
		{
			minVertex = pq1.top().ff;
			pq1.pop();
		}
		visited[minVertex] = true;
		//explore all the neighbours of minVertex and update accordingly
		for (int j = 0; j < edges[minVertex].size(); j++)
		{
			if (visited[edges[minVertex][j].ff])
				continue;
			if (weight[edges[minVertex][j].ff] > edges[minVertex][j].ss)
			{
				//update the current weigth of the neighbour and change its parent also
				weight[edges[minVertex][j].ff] = edges[minVertex][j].ss;
				parent[edges[minVertex][j].ff] = minVertex;
				pq1.push(mp(edges[minVertex][j].ff, weight[edges[minVertex][j].ff]));
			}
		}
	}
	for (int i = 1; i < n; i++)
		cout << i << " " << parent[i] << " " << weight[i] << endl;
}
int main()
{
	fastio();
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	freopen("Error.txt", "w", stderr);
#endif
	int n, e;
	cin >> n >> e;
	vector<pair<int, ll>> *edges = new vector<pair<int, ll>>[n];
	//input is taken considering 0 based indexing
	//make changes accordingly
	for (int i = 0; i < e; i++)
	{
		int a, b;
		ll weight;
		cin >> a >> b >> weight;
		edges[a].pb(mp(b, weight));
		edges[b].pb(mp(a, weight));
	}
	prims(edges, n);
	return 0;
}
