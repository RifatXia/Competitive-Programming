//Dynamic Programming and Backtracking
//Test - https://vjudge.net/contest/417234#problem/G
//RifatXia

#include <bits/stdc++.h>
using namespace std;

double eps = 1e-9;
// double pi = acos(-1);

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

int row, col;
int dp[10][10];

int work(int x, int y)
{
	if(dp[x][y] != 0)
		return dp[x][y];

	if(x == row && y == col)
		return dp[x][y] = 1;

	if(x < row)
		dp[x][y] += work(x + 1, y);

	if(y < col)
		dp[x][y] += work(x, y + 1);

	return dp[x][y];
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
	while(t--)
	{
		mem(dp, 0);
		cin >> row >> col;
		cout << work(1, 1) << en;
	}

	return 0;
}
