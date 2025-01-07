const int block_size = 450;
bool compare(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
	int b1 = p1.ff.ff / block_size;
	int b2 = p2.ff.ff / block_size;
	if (b1 == b2)
		return b1 % 2 == 0 ? (p1.ff.ss < p2.ff.ss) : (p1.ff.ss > p2.ff.ss);
	return b1 < b2;
}
int main()
{
	fastio();
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	freopen("Error.txt", "w", stderr);
#endif
	auto start1 = high_resolution_clock::now();
	int n, q;
	cin >> n >> q;
	// block_size = int(sqrt(n + 0.0) + 1);
	int *arr = new int[n];
	int *freq = new int[n + 1]();
	int number = 1;
	map<int, int> coordinate_compression;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (coordinate_compression.find(arr[i]) == coordinate_compression.end())
		{
			coordinate_compression[arr[i]] = number;
			arr[i] = number;
			number++;
		}
		else
			arr[i] = coordinate_compression[arr[i]];
	}
	int start = 0;
	int end = -1;
	vector<pair<pair<int, int>, int>> ans(q);
	for (int i = 0; i < q; i ++)
	{
		int a, b;
		cin >> a >> b;
		ans[i] = {{a, b}, i};
	}
	sort(ans.begin(), ans.end(), compare);
	int *ans1 = new int[q];
	int count = 0;
	for (auto i : ans)
	{
		pair<pair<int, int>, int> p1 = i;
		int right = p1.ff.ss - 1;
		int left = p1.ff.ff - 1;
		while (start < left)
		{
			int x = arr[start];
			freq[x]--;
			if (freq[x] == 0)
				count--;
			start++;
		}
		while (start > left)
		{
			start--;
			int x = arr[start];
			freq[x]++;
			if (freq[x] == 1)
				count++;
		}
		while (end < right)
		{
			end++;
			int x = arr[end];
			freq[x]++;
			if (freq[x] == 1)
				count++;
		}
		while (end > right)
		{
			int x = arr[end];
			freq[x]--;
			if (freq[x] == 0)
				count--;
			end--;
		}
		ans1[p1.ss] = count;
	}
	for (int i = 0; i < q; i++)
		cout << ans1[i] << "\n";
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration.count() / 1000.0 << endl;
#endif
	return 0;
}
