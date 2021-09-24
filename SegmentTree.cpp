// Basic Segment Tree with queries to find the max in a given range 
// RifatXia

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
#define all(v) v.begin(), v.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define valid(nx, ny, row, col) nx >= 0 && nx < row && ny >= 0 && ny < col
#define pii pair <int, int>
#define inf int(2e9)
#define mod int(1e9 + 7)

const int lim = 1e5 + 10;
int num[lim], seg[4 * lim];

// funtion to build the segment tree 
void build(int ind, int low, int high)
{
    // the values of the leaf 
    if(low == high)
    {
        seg[ind] = num[low];
        return ;
    }
    
    int mid = (low + high)/2;

    // proceeding towards the left and the right of the segment tree 
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query(int ind, int low, int high, int l, int r)
{
    // completely inside the range
    if(low >= l && high <= r)
        return seg[ind];

    // completely out of range
    if(high < l || low > r)
        return -inf;

    // intersects the range and so, checking on both the left and the right 
    int mid = (low + high)/2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);

    return max(left, right);
}

int main(void)
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    fast_io

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    build(0, 0, n - 1);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, n - 1, l, r) << en;
    }

    return 0;
}
