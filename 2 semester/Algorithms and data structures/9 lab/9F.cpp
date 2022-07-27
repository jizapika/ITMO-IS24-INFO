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
vi H;
void dfs(int a)
{
    H[a] = 2;
    for(int i = 0; i < G[a].size(); i++) if(H[G[a][i]] == -1) dfs(G[a][i]);
    for(int i = 0; i < G[a].size(); i++) if(H[G[a][i]] == 2) H[a] = 1;
}
void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    G.resize(n+1);
    H.resize(n+1, -1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
    }
    dfs(s);
    if(H[s] == 1) cout << "First player wins";
    else cout << "Second player wins";
}
signed main()
{
  //  freopen("game.in", "r", stdin);
    //freopen("game.out", "w", stdout);
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)solve();
}
