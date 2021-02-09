//Determine whether a graph is bicolourable or not using BFS
//Test - https://vjudge.net/contest/401863?fbclid=IwAR3kt-pDxe3mIi5f6YRDNDO1pp3mxoD--n2Q0X11CRqOmn2sJYxvHV-MfME#problem/C
//RifatXia

#include <bits/stdc++.h>
using namespace std;

double eps = 1e-9;
double pi = acos(-1);

int fx[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int fy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fast_io ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define ull unsigned long long
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
#define DEBUG(v) cout << v << " "; cout << en;
#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b
#define mem(a, b) memset(a, b, sizeof(a))
#define valid(nx, ny, row, col) nx >= 0 && nx < row && ny >= 0 && ny < col

vector <int> graph[210];
int color[210];
bool ans = true;

void bfs(int node)
{
	color[node] = 0;

	queue <int> q;
	q.push(node);
	while(!q.empty())
	{
		int f = q.front();
		q.pop();

		for(int i = 0; i < graph[f].size(); i++)
		{
			int c = graph[f][i];

			if(color[c] == -1)
			{
				int tmp = !color[f];
				color[c] = tmp;
				q.push(c);
			}

			if(color[c] == color[f])
				ans = false;
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

	int n;
	while(cin >> n && n)
	{
		mem(color, -1);
		mem(graph, 0);
		ans = true;

		int m;
		cin >> m;

		int a, b;
		for(int i = 0; i < m; i++)
		{
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		bfs(0);

		if(ans)
			cout << "BICOLORABLE.\n";
		else
			cout << "NOT BICOLORABLE.\n";
	}	

	return 0;
}
