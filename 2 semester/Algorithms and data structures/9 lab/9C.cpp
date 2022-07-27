#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define vp vector<pii>
using namespace std;
vector<vi> G;
vi color;
void dfs(int a, int p)
{
    color[a] = 3 - color[p];
    for(int i = 0; i < G[a].size(); i++) if(color[G[a][i]] == 0)
    {
        dfs(G[a][i], a);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    G.resize(n+1);
    color.resize(n+1, 0);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    for(int i = 1; i <= n; i++) if(color[i] == 0)
    {
        color[i] = 2;
        dfs(i, i);
    }
    int t = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < G[i].size(); j++) if(color[G[i][j]] == color[i]) t = 0;
    }
    if(t) cout << "YES";
    else cout << "NO";
}
signed main()
{
    freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out", "w", stdout);
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)solve();
}
