//Calculate the number of possible ways to make the amount using the following coins - 1, 5, 10, 25, 50
//Test - https://vjudge.net/contest/417234#problem/C
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

const int lim = 7500;
int coin[10][lim + 10] = {};
int num[] = {1, 5, 10, 25, 50};
void work()
{
	for(int i = 0; i < 5; i++)
	{
		coin[i][0] = 1;
	}

	for(int i = 0; i < 5; i++)
	{
		for(int j = 1; j <= lim; j++)
		{
			if(i == 0)
			{
				coin[i][j] = 1;
			}
			else if(j < num[i])
			{
				coin[i][j] = coin[i - 1][j];
			}
			else
			{
				coin[i][j] = coin[i - 1][j] + coin[i][j - num[i]];
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

	work();

	int n;
	while(cin >> n)
	{
		cout << coin[4][n] << en;
	}

	return 0;
}
