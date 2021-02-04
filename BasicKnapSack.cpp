//The Basic KnapSack Problem
//s - maximum capacity of the knapsack
//n - number of items
//size - capacity of the item
//value - price of the item
//pos - current position of the pointed item
//dp - keeps track by memoization
//Test - https://vjudge.net/contest/417234#problem/I
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

const int lim = 2010;
int dp[lim][lim];
int size[lim], value[lim], s, n;

int knapsack(int pos, int cap)
{
	if(pos == n)
		return 0;

	if(dp[pos][cap] != -1)
		return dp[pos][cap];

	int ans = knapsack(pos + 1, cap); //if we skip the current item

	if(cap >= size[pos])
	{
		int take = knapsack(pos + 1, cap - size[pos]) + value[pos]; //if we take the current item
		ans = max(ans, take);
	}

	return dp[pos][cap] = ans;
}

int main(void)
{
    //reading data from file
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	fast_io

	mem(dp, -1);

	cin >> s >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> value[i] >> size[i];
	}

	cout << knapsack(0, s) << en;

	return 0;
}
