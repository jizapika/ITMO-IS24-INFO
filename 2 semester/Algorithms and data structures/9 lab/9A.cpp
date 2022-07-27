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
vi ans;
vi color;
int t = 1;
void dfs(int a)
{
    color[a] = 1;
    for(int i = 0; i < G[a].size(); i++)
    {
        if(color[G[a][i]] == 0)
        {
            dfs(G[a][i]);
        }
        else if(color[G[a][i]] == 1) t = 0;
    }
    color[a] = 2;
    ans.pb(a);
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
    }
    int f = 0;
    for(int i = 1; i <= n; i++) if(color[i] == 0) dfs(i);
    if(!t)
    {
        cout << -1;
        return;
    }
    for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
}
signed main()
{
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)solve();
}
