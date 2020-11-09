// Find cycle in a directed graph using colours
// 0 -> not visited
// 1 -> visited but not finished
// 2 -> visited and finished
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
#define DEBUG(v) cout << v << " "; cout << en;
#define mem(a, b) memset(a, b, sizeof(a))
#define valid(nx, ny, row, col) nx >= 0 && nx < row && ny >= 0 && ny < col

vector <int> graph[1000];
int color[1000];
bool ans = false;

void cycleFind(int node)
{
	color[node] = 1;

	for(int i = 0; i < graph[node].size(); i++)
	{
		int c = graph[node][i];

		if(color[c] == 0)
			cycleFind(c);
		else if(color[c] == 1)
			ans = true;
	}
	color[node] = 2;
}

int main(void)
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	fast_io

	mem(color, 0);

	int n, a, b;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
	}

	for(int i = 1; i <= n; i++)
	{
		if(color[i] == 0)
			cycleFind(i);
	}

	if(ans)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
