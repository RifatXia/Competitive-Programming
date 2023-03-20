//Printing the longest common subsequence between two strings
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

int lcs(int f, int s)
{
	if(f > a.size() || s > b.size())
		return 0;

	if(a[f] == b[s])
	{
		return lcs(f + 1, s + 1) + 1;
	}

	return max(lcs(f + 1, s), lcs(f, s + 1));
}

void print(int f, int s)
{
	if(f >= a.size() || s >= b.size())
		return;

	if(a[f] == b[s])
	{
		printf("%c", a[f]);
		return print(f + 1, s + 1);
	}

	if(lcs(f + 1, s) > lcs(f, s + 1))
		print(f + 1, s);
	
	else if(lcs(f + 1, s) < lcs(f, s + 1))
		print(f, s + 1);
	
	else
		print(f + 1, s + 1);
}

int main(void)
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	fast_io

	cin >> a >> b;

	print(0, 0);

	return 0;
}
