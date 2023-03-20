//Edit Distance
// Test : https://vjudge.net/contest/417234#problem/E
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

string a, b;
int dp[2020][2020];

int editDistance(int f, int s)
{
    //first pointer > first index returns the number of operations required to delete/add letters to second string
	if(f == a.size())
		return b.size() - s;
    //second pointer > second index returns the number of operations required to delete/add letters to first string
	if(s == b.size())
		return a.size() - f;
    
    //checking if already the pair is processed
	if(dp[f][s] != -1)
		return dp[f][s];

    //if the letters are same, no operations are needed
	if(a[f] == b[s])
	{
		return dp[f][s] = editDistance(f + 1, s + 1);
	}

    //when altering(deletion/insertion) is required, operations increase by 1
    //min is taken because minimum number of operations possible must be the answer
	int op1 = editDistance(f + 1, s);
	int op2 = editDistance(f, s + 1);
	int op3 = editDistance(f + 1, s + 1);

	return dp[f][s] = min(min(op1, op2), op3) + 1;
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
		mem(dp, -1);
		cin >> a >> b;
		cout << editDistance(0, 0) << en;	
	}

	return 0;
}
