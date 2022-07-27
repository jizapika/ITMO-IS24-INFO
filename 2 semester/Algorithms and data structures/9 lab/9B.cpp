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
vi cycle;
vi color;
void dfs(int a)
{
    color[a] = 1;
    for(int i = 0; i < G[a].size(); i++)
    {
        if(!cycle.empty()) return;
        int to = G[a][i];
        if(color[to] == 0)
        {
            dfs(to);
        }
        else if(color[to] == 1)
        {
            cycle.pb(to);
            while(to != a)
            {
                for(int j = 0; j < G[to].size(); j++) if(color[G[to][j]] == 1)
                {
                    to = G[to][j];
                    break;
                }
                cycle.pb(to);
            }
            return;
        }
    }
    color[a] = 2;
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
    for(int i = 1; i <= n; i++) if(color[i] == 0) dfs(i);
    if(cycle.empty()) cout << "NO";
    else
    {
        cout << "YES" << endl;
        for(int i = 0; i < cycle.size(); i++) cout << cycle[i] << " ";
    }
}
signed main()
{
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)solve();
}
