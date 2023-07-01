// Prime Multiples - generating subsets and numbers divisible by the primes in a given range
// Test - https://vjudge.net/contest/563116#problem/G
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

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}

template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}

void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

void RifatXia()
{
    #ifndef ONLINE_JUDGE
        #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stderr);
        freopen("out.txt", "a", stdout);
    #else
        #define debug(x...)
    #endif
}

#define fast_io ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define ull unsigned long long
#define en "\n"
#define ff first
#define ss second
#define sp(x) fixed << setprecision(x)
#define runtime cout << "Runtime: " << clock() * 1.0 / CLOCKS_PER_SEC << en;
#define SORT(v)  sort(v.begin(), v.end());
#define RSORT(v) sort(v.begin(), v.end(), greater<int>())
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

int main(void)
{
    RifatXia();
    fast_io

    ll n, k;
    cin >> n >> k;

    ll num[k];
    for(int i = 0; i < k; i++)
    {   
        cin >> num[i];
    }

    ll tot = 1 << k;
    map <ll, ll> mp;
    ll ans = 0;
    // generating all the subsets 
    for(int mask = 1; mask < tot; mask++)
    {
        ll take = n;
        for(int j = 0; j < k; j++)
        {
            // taking the number when the bit is set
            if(mask & (1 << j))
            {
                take /= num[j];
            }
        }
        mp[pop_cnt(mask)] += take;
    }

    // inclusion-exclusion part
    // The formula for the union - A U B U C = A + B + C - (A U B) - (A U C) - (B U C) - (A N B N C)
    // N - intersection, add when setbits are odd, or subtract otherwise 
    for(auto i : mp)
    {
        if (i.ff % 2 == 0)
            ans -= i.ss;
        else
            ans += i.ss;
    }

    cout << ans << en;

    return 0;
}
