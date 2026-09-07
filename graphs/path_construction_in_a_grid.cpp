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
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> a(n,vector<char>(m));
    queue<pll> q;
    ll sx{},sy{}, endx{}, endy{};
    vector<vector<bool>> vis(n, vector<bool>(m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                sx=i;
                sy=j;
                q.push({ i,j });
                vis[i][j]=true;
            }
            else if (a[i][j] == 'B') {
                endx = i;
                endy = j;
            }
        }
    }
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    char dir[4] = {'D','U','R','L'};
    vector<vector<char>> par(n,vector<char>(m));
    string s;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop(); 
        if(a[x][y]=='B'){
            cout << "YES" << endl;
            break;
        }
        for (ll d{};d < 4;d++) {
            ll nx = x + dx[d];
            ll ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == '#' || (vis[nx][ny] == true)){
                continue;
            }
            q.push({ nx,ny });
            par[nx][ny] = dir[d];
            vis[nx][ny] = true;
        }
    }
    if(!vis[endx][endy]){
        cout << "NO" << endl;
        return;
    }
    ll i=endx,j=endy;
    while(i!=sx || j!=sy){
        char d = par[i][j];
        s.push_back(d);
        if (d == 'D')
            i--;
        else if (d == 'U')
            i++;
        else if (d == 'R')
            j--;
        else if (d == 'L')
            j++;
    }
    reverse(all(s));
    cout << s.size() << endl;
    cout << s << endl;
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
