#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define vp vector<pii>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    int B[m], E[m], W[m];
    vector< vector<pii> > G(n+1);
    for(int i = 0; i < m; i++)
    {
        cin >> B[i] >> E[i] >> W[i];
        G[B[i]].pb({E[i], W[i]});
        G[E[i]].pb({B[i], W[i]});
    }
    set<pii> MI;
    int length = 0;
    vector<int> used(n+1, 0);
    used[1] = 1;
    vi mi(n+1, -1);
    for(int j = 0; j < G[1].size(); j++)
    {
        MI.insert({G[1][j].s, G[1][j].f});
        mi[G[1][j].f] = G[1][j].s;
    }
    while(!MI.empty())
    {
        set<pii> :: iterator it = MI.begin();
        if(used[(*it).s])
        {
            MI.erase(*it);
            continue;
        }
        length += (*it).f;
        int v = (*it).s;
        used[v] = 1;
        MI.erase(*it);
        for(int i = 0; i < G[v].size(); i++) if(!used[G[v][i].f])
        {
            if(mi[G[v][i].f] == -1) MI.insert({G[v][i].s, G[v][i].f});
            else if(mi[G[v][i].f] > G[v][i].s)
            {
                MI.erase({mi[G[v][i].f], G[v][i].f});
                mi[G[v][i].f] = G[v][i].s;
                MI.insert({mi[G[v][i].f], G[v][i].f});
            }
        }
    }
    cout << length;
}
signed main()
{
    freopen("spantree3.in", "r", stdin);
    freopen("spantree3.out", "w", stdout);
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)solve();
}
