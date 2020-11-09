// Finding the longest path in a tree
// Take the inputs
// apply the bfs from any node
// again apply bfs from the node with the mx distance
// the resulting will be the longest node
// RifatXia

#include <bits/stdc++.h>
using namespace std;

double eps = 1e-9;
double pi = acos(-1);

int fx[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int fy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

#define fast_io ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define en "\n"
#define ff first
#define ss second
#define sp(x) fixed << setprecision(x)
#define VECT(v)  vector<int>v
#define SCAN(v)  int temp; for(int i=0; i<n; i++) {cin>>temp; v.push_back(temp);}
#define PRINT(v) for(int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << en;
#define SORT(v)  sort(v.begin(), v.end());
#define RSORT(v) sort(v.begin(), v.end(), greater<>())
#define CASEP(v) cout<<"Case "<<tc<<": "<<v<<"\n"
#define mem(a, b) memset(a, b, sizeof(a))
#define valid(nx, ny, row, col) nx >= 0 && nx < row && ny >= 0 && ny < col

const int lim = 1000;

vector <int> graph[lim];
bool vis[lim + 10];
int len[lim + 10];

void dfs(int node, int p)
{
	vis[node] = true;
	
	if(p == -1)
		len[node] = 0;
	else
		len[node] = len[p] + 1;

	for(int i = 0; i < graph[node].size(); i++)
	{
		int c = graph[node][i];

		if(!vis[c])
		{
			dfs(c, node);
		}
	}
}

int main(void)
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	fast_io

	int n, a, b;
	cin >> n;

	mem(graph, 0);
	mem(vis, 0);
	mem(len, 0);

	for(int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, -1);

	int mx = 0, ans;
	for(int i = 1; i <= n; i++)
	{
		if(len[i] > mx)
		{
			mx = len[i];
			ans = i;
		}
	}

	mem(vis, 0);
	mem(len, 0);

	dfs(ans, -1);

	mx = 0, ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(len[i] > mx)
		{
			mx = len[i];
			ans = i;
		}
	}
	cout << ans << en;

	return 0;
}
