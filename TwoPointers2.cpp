//Find the maximum friends that can be gathered maximizing the friendship factor
//Two pointers manage the front and the back index and the pref array denotes the total factor in a range
//Test - https://vjudge.net/contest/435252#problem/R
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
#define RSORT(v) sort(v.begin(), v.end(), greater<int>())
#define CASEP(v) cout<<"Case "<<tc<<": "<<v<<"\n"
#define DEBUG(v) cout << v << " "; cout << en;
#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b
#define mem(a, b) memset(a, b, sizeof(a))
#define valid(nx, ny, row, col) nx >= 0 && nx < row && ny >= 0 && ny < col
#define pii pair <int, int>
#define inf (int)2e9
#define mod (int)1e9 + 7

struct demo
{
	int money, factor;
};

bool comp(demo p1, demo p2)
{
	return p1.money < p2.money;
}

int main(void)
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	fast_io

	int n, k;
	cin >> n >> k;

	demo num[n + 10];
	ll pref[n + 10] = {};

	for(int i = 1; i <= n; i++)
	{
		cin >> num[i].money >> num[i].factor;
	}

	sort(num + 1, num + n + 1, comp);

	for(int i = 1; i <= n; i++)
	{
		pref[i] = pref[i - 1] + num[i].factor;
	}

	ll ans = -1;
	int l = 1, r = 1;
	while(l <= n && r <= n)
	{
		if(num[r].money - num[l].money < k)
		{
			ans = MAX(ans, pref[r] - pref[l - 1]);
			r++;
		}
		else
		{
			l++;
		}
	}
	cout << ans << en;

	return 0;
}
