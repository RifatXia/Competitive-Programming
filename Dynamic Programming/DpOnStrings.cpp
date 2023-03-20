// DP on strings to find the common amongst them and place the rest of the letters accordingly
// Problem - https://vjudge.net/contest/499049#problem/G
// RifatXia

#include <bits/stdc++.h>
using namespace std;

double eps = 1e-9;
double pi = acos(-1);

int fx[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int fy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int pop_cnt(int n) {return __builtin_popcount(n);}
int clz(int n) {return __builtin_clz(n);}
int ctz(int n) {return __builtin_ctz(n);}
bool parity(int n) {return __builtin_parity(n);}

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
#define all(v) v.begin(), v.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define get_bit(num, pos) {num & (1 << pos)}
#define set_bit(num, pos) (num |= (1 << pos))
#define reset_bit(num, pos) {num &= ~(1 << pos)}
#define toggle_bit(num, pos) {num ^= (1 << pos)}
#define valid(nx, ny, row, col) nx >= 0 && nx < row && ny >= 0 && ny < col
#define pii pair <int, int>
#define vi vector <int>
#define vll vector <ll>
#define inf int(2e9)
#define mod int(1e9 + 7)

string a, b;
const int lim = 110;
string dp[lim][lim];

string work(int x, int y)
{
    if(x == a.size() || y == b.size())  
        return "";

    if(dp[x][y] != "-1")
        return dp[x][y];

    if(a[x] == b[y])
    {
        return dp[x][y] = a[x] + work(x + 1, y + 1);
    }

    string c = work(x + 1, y);
    string d = work(x, y + 1);

    if(c.size() > d.size())
        return dp[x][y] = c;
    else
        return dp[x][y] = d;
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
        for(int i = 0; i < lim; i++)
        {
            for(int j = 0; j < lim; j++)
            {
                dp[i][j] = "-1";
            }
        }
        string ans = work(0, 0);
        // cout << ans << en;

        int x = 0, y = 0;
        string fin = "";
        for(int i = 0; i < ans.size(); i++)
        {
            while(x < a.size() && ans[i] != a[x])
            {
                fin += a[x++];
            }
            while(y < b.size() && ans[i] != b[y])
            {
                fin += b[y++];
            }
            fin += ans[i];
            x++;    
            y++;
        }
        while(x < a.size())
            fin += a[x++];

        while(y < b.size())
            fin += b[y++];
            
        cout << fin << en;
    }

    return 0;
}
