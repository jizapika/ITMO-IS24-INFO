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
    for(int i = 1; i <= n; i++) cout << G[i].size() << " ";
}
signed main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)solve();
}
