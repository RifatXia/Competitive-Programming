// Minimum Spanning Tree Problem solved by Kruskal's Algorithm
// It is used to find the minimum cost incurred to form/break roads from a city to another city 
// Made by following Sakib's bhaiya's template
// Test - https://vjudge.net/contest/550961#problem/H 
// RifatXia

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define en "\n"

const int lim = 1e5 + 10;
int parent[lim], len[lim];

struct Edge
{
    int u, v, w;

    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator < (const Edge &q) const 
    {
        return w < q.w;
    }
};

vector <Edge> edge;

void make_set(int n)
{
    for(int i = 0; i <= n; i++)
    {
        parent[i] = i;
        len[i] = 1;
    }
}

int find_set(int v)
{
    if(parent[v] == v)
        return v;

    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if(a != b)
    {
        if(len[a] < len[b])
            swap(a, b);

        parent[b] = a;
        len[a] += len[b];
    }
}

ll kruskal()
{
    sort(edge.begin(), edge.end());
    ll ans = 0;

    for(auto x : edge)
    {
        int u = x.u, v = x.v, w = x.w;
        if(find_set(u) != find_set(v))
        {
            ans += w;
            union_set(u, v);
        }
    }
    return ans;
}

int main(void)
{
    fast_io

    int n, m;
    while(cin >> n >> m && n && m)
    {
        edge.clear();
        make_set(n);
        ll sum = 0;

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            sum += w;

            edge.push_back(Edge(u, v, w));
        }

        cout << sum - kruskal() << en;
    }

    return 0;
}
