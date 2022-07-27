#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define vp vector<pii>
using namespace std;
vector<int> used;
vector<int> comp;
vector<int> order;
int x = 0;
void dfs(int a, vector< vector<pii> > &G)
{
    used[a] = 1;
    for(int i = 0; i < G[a].size(); i++) if(!used[G[a][i].f])
    {
        dfs(G[a][i].f, G);
    }
}
void dfs1(int a, vector< vector<pii> > &G)
{
    used[a] = 1;
    for(int i = 0; i < G[a].size(); i++) if(!used[G[a][i].f])
    {
        dfs1(G[a][i].f, G);
    }
    order.pb(a);
}
void dfs2(int a, vector< vector<pii> > &G)
{
    comp[a] = x;
    for(int i = 0; i < G[a].size(); i++) if(comp[G[a][i].f] == -1)
    {
        dfs2(G[a][i].f, G);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int B[m], E[m], W[m];
    vector< vector<pii> > G(n+1);
    for(int i = 0; i < m; i++)
    {
        cin >> B[i] >> E[i] >> W[i];
        W[i] += 1000000005;
        G[B[i]].pb({E[i], W[i]});
    }
    for(int i = 1; i <= n; i++)
    {
        map<int, int> MIN;
        set<int> IN;
        for(int j = 0; j < G[i].size(); j++)
        {
            if(MIN[G[i][j].f] == 0) MIN[G[i][j].f] = G[i][j].s + 1;
            else MIN[G[i][j].f] = min(G[i][j].s + 1, MIN[G[i][j].f]);
            IN.insert(G[i][j].f);
        }
        G[i].clear();
        for(auto q: IN)
        {
            G[i].pb({q, MIN[q] - 1});
        }
    }
    used.resize(n+1, 0);
    used[1] = 1;
    dfs(1, G);
    int t = 1;
    for(int i = 1; i <= n; i++) t = min(t, used[i]);
    if(!t)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int sum = -1000000005 * (n - 1);
    while(true)
    {
        used.clear();
        used.resize(n+1, 0);
        int mI[n+1];
        mI[1] = 0;
        for(int i = 2; i <= n; i++) mI[i] = 10000000000;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < G[i].size(); j++) if(G[i][j].f != 1) mI[G[i][j].f] = min(mI[G[i][j].f], G[i][j].s);
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < G[i].size(); j++) if(G[i][j].f != 1) G[i][j].s -= mI[G[i][j].f];
        }
        for(int i = 2; i <= n; i++) sum += mI[i];
        vector< vector<pii> > K(n+1), K1(n+1);
        for(int i = 1; i <= n; i++) for(int j = 0; j < G[i].size(); j++) if(G[i][j].s == 0)
        {
            K[i].pb(G[i][j]);
            K1[G[i][j].f].pb({i, G[i][j].s});
        }
        dfs(1, K);
        int t = 1;
        for(int i = 1; i <= n; i++) t = min(t, used[i]);
        if(t) break;
        x = 1;
        order.clear();
        used.clear();
        comp.clear();
        used.resize(n+1, 0);
        comp.resize(n+1, -1);
        for(int i = 1; i <= n; i++) if(!used[i]) dfs1(i, K1);
        for(int i = order.size() - 1; i >= 0; i--) if(comp[order[i]] == -1)
        {
            dfs2(order[i], K);
            x++;
        }
        for(int i = 1; i <= n; i++) comp[i] = x - comp[i];
        vector< vector<pii> > C(x);
        for(int i = 1; i <= n; i++) for(int j = 0; j < G[i].size(); j++) if(comp[i] != comp[G[i][j].f])
        {
            C[comp[i]].pb({comp[G[i][j].f], G[i][j].s});
        }
        for(int i = 1; i < x; i++) if(C[i].size())
        {
            map<int, int> MIN;
            set<int> IN;
            for(int j = 0; j < C[i].size(); j++)
            {
                if(MIN[C[i][j].f] == 0) MIN[C[i][j].f] = C[i][j].s + 1;
                else MIN[C[i][j].f] = min(C[i][j].s + 1, MIN[C[i][j].f]);
                IN.insert(C[i][j].f);
            }
            C[i].clear();
            for(auto q: IN)
            {
                C[i].pb({q, MIN[q] - 1});
            }
        }
        n = x-1;
        G = C;
    }
    cout << sum;
}
signed main()
{
    freopen("chinese.in", "r", stdin);
    freopen("chinese.out", "w", stdout);
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)solve();
}
/*
5
8
1 2 5
2 3 1
4 3 2
4 5 1
5 4 1
2 5 2
3 2 1
1 5 5
YES
1000000008
*/
