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
vi used;
vi order;
void dfs(int a)
{
    used[a] = 1;
    for(int i = 0; i < G[a].size(); i++)
    {
        if(!used[G[a][i]]) dfs(G[a][i]);
    }
    order.pb(a);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    G.resize(n+1);
    used.resize(n+1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
    }
    for(int i = 1; i <= n; i++) if(used[i] == 0) dfs(i);
    int t = 1;
    for(int i = 1; i < order.size(); i++)
    {
        int tt = 0;
        for(int j = 0; j < G[order[i]].size(); j++)
        {
            if(G[order[i]][j] == order[i-1]) tt = 1;
        }
        t = min(t, tt);
    }
    if(t) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main()
{
    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)solve();
}
