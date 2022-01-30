// Output (length of longest common prefix * number of strings) from the given strings, processed one by one
// Problem - https://vjudge.net/contest/471397#problem/C
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
#define inf int(2e9)
#define mod int(1e9 + 7)

const int lim = 3;
int ans;

struct Trie
{
    struct node
    {
        int cnt, val;
        bool ending;

        node *next[lim];
        node *child[2];

        node()
        {
            cnt = 0, val = 0;
            ending = false;
            child[0] = NULL, child[1] = NULL;

            for (int i = 0; i < lim; i++)
                next[i] = NULL;
        }
    } * root;

    void init()
    {
        root = new node();
    }

    void insert_string(string s)
    {
        node *curr = root;

        for (int i = 0; i < s.size(); i++)
        {
            int id = s[i] - '0';
            if (curr->next[id] == NULL)
                curr->next[id] = new node();

            curr = curr->next[id];
            curr->cnt++;
            ans = max(ans, curr->cnt * (i + 1));
        }

        curr->ending = true;
    }

    bool search_string(string s)
    {
        node *curr = root;

        for (int i = 0; i < s.size(); i++)
        {
            int id = s[i] - '0';

            if (curr->next[id] == NULL)
                return false;

            curr = curr->next[id];
        }
        return (curr->ending);
    }

    int word_cnt(string s)
    {
        node *curr = root;
        for (int i = 0; i < s.size(); i++)
        {
            int id = s[i] - '0';
            if (curr->next[id] == NULL)
                return 0;

            curr = curr->next[id];
        }
        return curr->cnt;
    }
};

int main(void)
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    fast_io

    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        Trie trie;
        trie.init();

        int n;
        cin >> n;
        string s[n + 10];
        ans = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> s[i];
            trie.insert_string(s[i]);
        }

        cout << ans << en;
    }

    return 0;
}
