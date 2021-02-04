//Longest Common Subsequence
//Test - https://vjudge.net/contest/417234#problem/N
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

const int lim = 1010;
int dp[lim][lim];
string a, b;

int lcs(int f, int s)
{
	//base case : when the pointers pos > index, returns 0
	if(f == a.size() || s == b.size())
		return 0;

	//checking whether the same pair is processed before
	if(dp[f][s] != -1)
		return dp[f][s];

	//both the indexes have the same letter
	if(a[f] == b[s])
	{
		return dp[f][s] = lcs(f + 1, s + 1) + 1;
	}

	//max of either the index of the first or the second string
	return dp[f][s] = max(lcs(f, s + 1), lcs(f + 1, s));
}

int main(void)
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	fast_io

	while(cin >> a >> b)
	{
		mem(dp, -1);
		cout << lcs(0, 0) << en;
	}

	return 0;
}
