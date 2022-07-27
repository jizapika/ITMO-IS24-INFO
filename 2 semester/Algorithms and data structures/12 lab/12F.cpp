#include<bits/stdc++.h>

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define f first
#define s second
#define int long long

using namespace std;

vector<vi> G;
vector<pii> DP;
void dfs(int a)
{
    for(int i = 0; i < G[a].size(); i++)
    {
        dfs(G[a][i]);
        DP[a].f += DP[G[a][i]].s;
        DP[a].s += DP[G[a][i]].f;
    }
    DP[a].s = max(DP[a].f, DP[a].s);
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("selectw.in", "r", stdin);
    freopen("selectw.out", "w", stdout);
    int n;
    cin >> n;
    G.resize(n+1);
    DP.resize(n+1, {0, 1});
    for(int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].pb(i);
        DP[i].s = b;
    }
    dfs(G[0][0]);
    cout << max(DP[G[0][0]].f, DP[G[0][0]].s);
}
