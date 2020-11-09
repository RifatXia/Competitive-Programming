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

const int lim = 1000;

int parent[lim + 10];
int size[lim + 10];

int findParent(int n)
{
	if(parent[n] == n)
		return n;
	else
		return parent[n] = findParent(parent[n]);
}

void setUnion(int a, int b)
{
	a = findParent(a);
	b = findParent(b);

	if(a != b)
	{
		if(size[a] < size[b])
			swap(a, b);

		parent[b] = a;
		size[a] += size[b];
	}
}

int main(void)
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	fast_io

	int nodes, edges, a, b;
	cin >> nodes >> edges;

	for(int i = 1; i <= nodes; i++)
	{
		parent[i] = i;
		size[i] = 1;
	}

	for(int i = 0; i < edges; i++)
	{
		cin >> a >> b;
		setUnion(a, b);
	}

	for(int i = 1; i <= nodes; i++)
	{
		cout << findParent(i) << " ";
	}

	return 0;
}
