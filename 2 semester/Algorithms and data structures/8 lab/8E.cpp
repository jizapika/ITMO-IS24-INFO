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
    D.resize(n+1, 1000000);
    D[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < G[cur].size(); i++)
        {
            if(D[G[cur][i]] > D[cur] + 1)
            {
                D[G[cur][i]] = D[cur] + 1;
                q.push(G[cur][i]);
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << D[i] << " ";
}
signed main()
{
    freopen("pathbge1.in", "r", stdin);
    freopen("pathbge1.out", "w", stdout);
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)solve();
}
