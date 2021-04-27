//A simple implementation of two pointers
//Test - https://vjudge.net/contest/435252#problem/B
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
		int n, k;
		cin >> n >> k;

		vector <int> v(n), ans;
		for(int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		int l = 0, r = 0;
		ll sum = 0;
		map <int, int> mp;
		while(r < n)
		{
			sum += v[r];
			
			while(sum > k)
			{
				sum -= v[l];
				l++;
			}
			
			if(sum <= k)
			{
				int num = r - l + 1;
				if(mp[num] == 0)
				{
					ans.push_back(num);
					mp[num] = sum;
				}
				else if(sum < mp[num])
				{
					mp[num] = sum;
				}
			}
			r++;
		}
		RSORT(ans);
		cout << mp[ans[0]] << " " << ans[0] << en;
	}

	return 0;
}
