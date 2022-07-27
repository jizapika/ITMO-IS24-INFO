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
    G.resize(n*m);
    D.resize(n*m, 1000000);
    int s, t;
    int A[n][m];
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) A[i][j] = 0;
    for(int i = 0; i < n; i++)
    {
        string S;
        cin >> S;
        for(int j = 0; j < m; j++)
        {
            if(S[j] == 'S') s = i*m + j;
            if(S[j] == 'T') t = i*m + j;
            if(S[j] == '.' || S[j] == 'T') A[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    {
        if(i > 0 && A[i-1][j]) G[i*m + j].pb(i*m + j - m);
        if(j > 0 && A[i][j-1]) G[i*m + j].pb(i*m + j - 1);
        if(i < n-1 && A[i+1][j]) G[i*m + j].pb(i*m + j + m);
        if(j < m-1 && A[i][j+1]) G[i*m + j].pb(i*m + j + 1);
    }
    D[s] = 0;
    queue<int> q;
    q.push(s);
    int P[n*m];
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
                P[G[cur][i]] = cur;
            }
        }
    }
    if(D[t] == 1000000) {cout << -1; return;}
    cout << D[t] << endl;
    vector<char> ans;
    while(t != s)
    {
        if(P[t] == t - m) ans.pb('D');
        else if(P[t] == t - 1) ans.pb('R');
        else if(P[t] == t + m) ans.pb('U');
        else if(P[t] == t + 1) ans.pb('L');
        t = P[t];
    }
    for(int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
}
signed main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)solve();
}
