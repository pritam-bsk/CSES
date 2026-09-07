/*
You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n \times m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).
Output
Print one integer: the number of rooms.
Constraints

1 \le n,m \le 1000

Example
Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3
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
 
 
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    int comp{};
    vector<vector<bool>> vis(n, vector<bool>(m));
    queue<pll> q;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++)
        {
            if (a[i][j] == '.' && !vis[i][j]) {
                comp++;
                q.push({ i,j });
                vis[i][j] = true;
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (ll d{};d < 4;d++) {
                        ll nx = x + dx[d];
                        ll ny = y + dy[d];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == '#' || (vis[nx][ny] == true))continue;
                        q.push({ nx,ny });
                        vis[nx][ny] = true;
                    }
                }
            }
 
        }
    }
    cout << comp << endl;
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
