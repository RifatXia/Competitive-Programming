//Finding the lcs of 3 strings using a 3d dp array
//Test - https://vjudge.net/problem/LightOJ-1159
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

string a, b, c;
int dp[60][60][60];

int lcs(int f, int s, int t)
{
	if(f == a.size() || s == b.size() || t == c.size())
	{
		return 0;
	}

	if(a[f] == b[s] && a[f] == c[t])
	{
		if(dp[f][s][t] != -1)
			return dp[f][s][t];
		else
			return dp[f][s][t] = lcs(f + 1, s + 1, t + 1) + 1;
	}

	int one, two, three;

	if(dp[f + 1][s][t] != -1)
		one = dp[f + 1][s][t];
	else
		one = dp[f + 1][s][t] = lcs(f + 1, s, t);

	if(dp[f][s + 1][t] != -1)
		two = dp[f][s + 1][t];
	else
		two = dp[f][s + 1][t] = lcs(f, s + 1, t);

	if(dp[f][s][t + 1] != -1)
		three = dp[f][s][t + 1];
	else
		three = dp[f][s][t + 1] = lcs(f, s, t + 1);

	return max(max(one, two), three);
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
		mem(dp, -1);
		cin >> a >> b >> c;
		cout << "Case " << tc << ": " << lcs(0, 0, 0) << en;	
	}

	return 0;
}
