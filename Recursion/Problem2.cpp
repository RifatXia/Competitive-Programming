// Problem - https://www.techiedelight.com/find-distinct-combinations-given-length-repetition-allowed/
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

// printing the vector 
void printer(vector <int> v)
{
    for(auto i : v)
        cout << i << " ";
    
    cout << en;
}

void combo(int i, int k, vector <int> v, vector <int> ans)
{
    // no more elements can be taken, needs to return 
    if(k == 0)
        return printer(ans);
    
    // loop from the start to end 
    for(int j = i; j < v.size(); j++)
    {
        ans.push_back(v[j]);

        // calling the function again but with one less element, since it is already inserted 
        combo(j, k - 1, v, ans);

        // backtracking 
        ans.pop_back();
    }
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

    vector <int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector <int> ans;
    combo(0, k, v, ans);

    return 0;
}
