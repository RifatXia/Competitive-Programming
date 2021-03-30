//Dijkstra's Algorithm - Single Source shortest path
//Works for both directed and undirected graph
//Doesn't work for negative edges
//Sakib bhaiya's implementation of Dijkstra's Algorithm
//Test - https://vjudge.net/problem/SPOJ-EZDIJKST
//RifatXia

#include <bits/stdc++.h>
using namespace std;

double eps = 1e-9;
double pi = acos(-1);
const int inf = 2e9;

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
#define pii pair <int, int>
#define mod (int)1e9 + 7

const int lim = 100010;
int n, m, a, b, c, src, des;
vector <pii> graph[lim + 10];
int cost[lim + 10], path[lim + 10];
bool vis[lim + 10];

void dijkstra()
{
	//This pq holds the elements in ascending order
	//It ensures that the neighbouring node with the smallest distance is selected
	priority_queue <pii, vector <pii>, greater <pii> > pq;
	
	//cost : the distance of any node from the source
	//The distance of the source from the source will be zero
	cost[src] = 0;

	//The current distance and the node is inserted in pq
	pq.push({cost[src], src});

	while(!pq.empty())
	{
		pii top = pq.top();
		pq.pop();

		//first = distance of node
		//second = the node
		int c = top.ff;
		int s = top.ss;

		//no need to continue if already visited
		if(vis[s])
			continue;

		vis[s] = true;

		for(int i = 0; i < graph[s].size(); i++)
		{
			pii next = graph[s][i];

			//Here since the graph is accessed, graph has a node from A to B
			//Here first = node B
			//second = weight of the edge A -> B
			int cx = next.ss;
			int sx = next.ff;

			//if distance is not edited before/not connected
			//or if the weight of the direct route is greater than that of the other route
			//then the weight of the route needs to be updated
			if(cost[sx] == inf || cost[sx] > cost[s] + cx)
			{
				cost[sx] = cost[s] + cx;
				
				//path stores the parent of a node
				path[sx] = s;
				pq.push({cost[sx], sx});
			}
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

	int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++)
	{
		cin >> n >> m;

		for(int i = 0; i <= lim; i++)
		{
			graph[i].clear();
			cost[i] = inf;
			vis[i] = false;
		}

		for(int i = 0; i < m; i++)
		{
			cin >> a >> b >> c;

			//The edge is from A -> B, can be inserted in the graph in the following way
			graph[a].push_back({b, c});
		}

		cin >> src >> des;
		dijkstra();

		if(cost[des] != inf)
			cout << cost[des] << en;
		else
			cout << "NO\n";
	}

	return 0;
}
