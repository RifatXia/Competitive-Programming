// functions of a segment tree - answer sum queries in log(N) time, update values and sum in log(N) time 
// Problem - https://vjudge.net/contest/401932#problem/J
// RifatXia
#include <bits/stdc++.h>
using namespace std;

#define en "\n"

const int lim = 1e5 + 10;
ll num[lim], seg[4 * lim], lazy[4 * lim];

// building the segment tree according to the input
void build(int i, int low, int high)
{
    if(low == high)
    {
        seg[i] = num[low];
        return ;
    }

//     if leaf node is not reached, keep on moving left and right accordingly 
    int mid = (low + high)/2;
    build(2 * i + 1, low, mid);
    build(2 * i + 2, mid + 1, high);
    
//     updating the latest value of the sum in the range
    seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
}

// updating the values in a range 
void update(int i, int low, int high, int l, int r, int x)
{
//     completely out of range 
    if(high < l || low > r)
        return ;

//     completely in the range 
    if(high <= r && low >= l)
    {
        lazy[i] += x;
        return ;
    }

//     if any node is not updated, update its child
    if(lazy[i] != 0)
    {
        lazy[2 * i + 1] += lazy[i];
        lazy[2 * i + 2] += lazy[i];
        lazy[i] = 0;
    }

//     if child nodes exist proceed towards left and right accordingly 
    int mid = (low + high)/2;
    update(2 * i + 1, low, mid, l, r, x);
    update(2 * i + 2, mid + 1, high, l, r, x);
    
//     update the segment tree with the latest values 
    seg[i] = seg[2 * i + 1] + lazy[2 * i + 1] * (mid - low + 1) + seg[2 * i + 2] + lazy[2 * i + 2] * (high - mid);
}

// calculating the updated summation 
ll sum(int i, int low, int high, int l, int r)
{
//     completely out of range 
    if(high < l || low > r)
        return 0;

//     completely in range 
    if(high <= r && low >= l)
    {
        return seg[i] + lazy[i] * (high - low + 1);
    }

//     proceeding towards the left and the right child as the range intercepts the index of the node
    int mid = (low + high)/2;
    ll ans = sum(2 * i + 1, low, mid, l, r) + sum(2 * i + 2, mid + 1, high, l, r);
    seg[i] = seg[2 * i + 1] + lazy[2 * i + 1] * (mid - low + 1) + seg[2 * i + 2] + lazy[2 * i + 2] * (high - mid);

    return ans;
}

int main(void)
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        int n, q;
        cin >> n >> q;

        for(int i = 0; i < n; i++)
        {
            cin >> num[i];
        }

        for(int i = 0; i < 4 * n; i++)
        {
            lazy[i] = 0;
            seg[i] = 0;
        }

        build(0, 0, n - 1);

        cout << "Case " << tc << ":\n";

        int x, l, r, val;
        for(int i = 0; i < q; i++)
        {
            cin >> x;

            if(x == 1)
            {
                cin >> val;
                ll ans = sum(0, 0, n - 1, val, val);
                cout << ans << en;
                
                update(0, 0, n - 1, val, val, -ans);
            }
            else if(x == 2)
            {
                cin >> l >> val;
                update(0, 0, n - 1, l , l, val);
            }
            else if(x == 3)
            {
                cin >> l >> r;
                cout << sum(0, 0, n - 1, l, r) << en;
            }
        }
    }

    return 0;
}
