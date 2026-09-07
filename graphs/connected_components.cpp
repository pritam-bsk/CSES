/*
Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.
Your task is to find out the minimum number of roads required, and also determine which roads should be built.
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.
Output
First print an integer k: the number of required roads.
Then, print k lines that describe the new roads. You can print any valid solution.
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
4 2
1 2
3 4

Output:
1
2 3
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long
#define all(x) (x).begin(), (x).end()
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;

class DSU {
public:
    vector<ll> size;
    vector<ll> parent;
public:
    DSU(ll n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    ll findUPar(ll node) {
        if (node == parent[node]) return node;
        parent[node] = findUPar(parent[node]);
        return parent[node];
    }
    void unionBySize(ll u, ll v) {
        ll up_u = findUPar(u);
        ll up_v = findUPar(v);
        if (up_u == up_v) return;
        if (size[up_u] < size[up_v]) {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
    bool isConnected(ll u, ll v) {
        return findUPar(u) == findUPar(v);
    }
};
void solve()
{
    ll n, m;
    cin >> n >> m;
    DSU ds(n);
    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        ds.unionBySize(u, v);
    }

    vll comp;
    for (ll i = 1; i <= n; i++) {
        if (ds.findUPar(i) == i) comp.push_back(i);
    }
    cout << comp.size() - 1 << endl;
    for (ll i = 0; i < comp.size() - 1; i++) {
        cout << comp[i] << " " << comp[i + 1] << endl;
    }
}

int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
