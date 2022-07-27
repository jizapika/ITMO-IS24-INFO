#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define vp vector<pii>
using namespace std;
vector<vi> G1, G2;
vi order;
vi comp;
vi used;
int x = 0;
void dfs1(int a)
{
    used[a] = 1;
    for(int i = 0; i < G2[a].size(); i++) if(!used[G2[a][i]])
    {
        dfs1(G2[a][i]);
    }
    order.pb(a);
}
void dfs2(int a)
{
    comp[a] = x;
    for(int i = 0; i < G1[a].size(); i++) if(comp[G1[a][i]] == -1)
    {
        dfs2(G1[a][i]);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    G1.resize(n+1);
    G2.resize(n+1);
    comp.resize(n+1, -1);
    used.resize(n+1, 0);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G1[a].pb(b);
        G2[b].pb(a);
    }
    for(int i = 1; i <= n; i++) if(!used[i]) dfs1(i);
    for(int i = order.size() - 1; i >= 0; i--) if(comp[order[i]] == -1)
    {
        dfs2(order[i]);
        x++;
    }
    cout << x << endl;
    for(int i = 1; i <= n; i++) cout << x - comp[i] << " ";
}
signed main()
{
    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)solve();
}
