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


void solve()
{
    int n, m;
    cin >> n >> m;
    vvll adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n + 1, false);
    vector<ll> parent(n + 1, 0);
    queue<ll> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        ll par = q.front();
        q.pop();
        if (par == n) {
            break;
        }
        for (auto& ch : adj[par]) {
            if (vis[ch])continue;
            parent[ch] = par;
            q.push(ch);
            vis[ch] = true;
        }
    }
    if (!vis[n]) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<ll> path;
    ll ch = n;
    while (ch != 0)
    {
        path.push_back(ch);
        ch = parent[ch];
    }
    reverse(all(path));
    cout << path.size() << endl;
    for (ll i = 0; i < path.size(); i++)
        cout << path[i] << ' ';
    cout << endl;

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
