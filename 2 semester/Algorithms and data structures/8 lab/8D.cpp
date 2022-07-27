#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define vp vector<pii>
using namespace std;
vector<vector<int> >G;
vector<int>D;
void dfs(int a, int p)
{
    D[a] = D[p];
    for(int i = 0; i < G[a].size(); i++) if(D[G[a][i]] == -1)
    {
        dfs(G[a][i], a);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    G.resize(n+1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    D.resize(n+1, -1);
    int x = 1;
    for(int i = 1; i <= n; i++) if(D[i] == -1)
    {
        D[i] = x;
        dfs(i, i);
        x++;
    }
    cout << x-1 << endl;
    for(int i = 1; i <= n; i++) cout << D[i] << " ";
}
signed main()
{
    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)solve();
}
