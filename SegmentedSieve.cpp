//Find the prime numbers in a given range
//Here the size of n can be upto 1e9 so by using sieve it cannot be done, since the index of the array would be way bigger
//Test - https://www.spoj.com/problems/PRIME1
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

const int lim = 34000;
bool prime[lim + 10] = {};
vector <int> pNum;

//Generating the primes upto square root of n, n = 1e9
void work()
{
	mem(prime, true);
	prime[0] = prime[1] = false;
	for(int i = 2; i <= lim; i++)
	{
		if(prime[i])
		{
			for(int j = i * i; j <= lim; j += i)
			{
				prime[j] = false;
			}
		}
	}

	for(int i = 2; i <= lim; i++)
	{
		if(prime[i])
		{
			pNum.push_back(i);
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

	int t, k = 0;
	cin >> t;
	while(t--)
	{
		if(k++ > 0)
			cout << en;

		int a, b;
		cin >> a >> b;

		bool check[b - a + 10];
		mem(check, true);
		
		int st = max(2, a);
		for(int i = st; i <= b; i++)
		{
            		//If the number is divisble by any prime number, it is not a prime
			for(int j = 0; j < pNum.size() && pNum[j] < i; j++)
			{
				if(i % pNum[j] == 0)
				{
					check[i - a] = false;
					break;
				}
			}
		}

        	//Printing out the answers
		for(int i = st; i <= b; i++)
		{
			if(check[i - a])
			{
				cout << i << en;
			}
		}
	}

	return 0;
}
