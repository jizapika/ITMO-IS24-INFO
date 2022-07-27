#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define f first
#define s second
using namespace std;
struct edge
{
    int u;
    int to;
    int w;
};
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    unordered_map< int, unordered_map<int, int> > A;
    vector< edge > E;
    while(m--)
    {
        edge e;
        cin >> e.u >> e.to >> e.w;
        e.u--; e.to--;
        E.pb(e);
        A[e.u][e.to] = e.w;
        for(int i = 0; i < E.size(); i++) if(E[i].u == e.u && E[i].to == e.to) A[e.u][e.to] = min(A[E[i].u][E[i].to], E[i].w);
    }
    int D[n];
    for(int j = 0; j < n; j++) D[j] = 8000000000000000001;
    int used[n];
    for(int i = 0; i < n; i++) used[i] = 0;
    D[s] = 0;
    used[s] = 1;
    vector<int> neg(n, 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < E.size(); j++)
        {
            used[E[j].to] = max(used[E[j].u], used[E[j].to]);
            if(D[E[j].u] + A[E[j].u][E[j].to] > -8000000000000000001 && used[E[j].to]) D[E[j].to] = min(D[E[j].u] + A[E[j].u][E[j].to], D[E[j].to]);
            if(D[E[j].u] + A[E[j].u][E[j].to] <= -8000000000000000001 && used[E[j].to]) neg[E[j].to] = 1;
        }
    }
    for(int j = 0; j < E.size(); j++) if(D[E[j].to] > D[E[j].u] + A[E[j].u][E[j].to] && used[E[j].to]) neg[E[j].to] = 1;

    for(int i = 0; i < n; i++) for(int j = 0; j < E.size(); j++) neg[E[j].to] = max(neg[E[j].u], neg[E[j].to]);
    for(int i = 0; i < n; i++)
    {
        if(!used[i]) cout << "*" << endl;
        else if(neg[i]) cout << "-" << endl;
        else cout << D[i] << endl;
    }
}
