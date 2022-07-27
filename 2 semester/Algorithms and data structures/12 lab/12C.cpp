#include<bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 //   freopen("search4.in", "r", stdin);
   // freopen("search4.out", "w", stdout);
    string S, T;
    cin >> S >> T;
    int n = S.length(), m = T.length();
    vector <vector <bool> > P(n, vector<bool>(m, false));
    int DP[m];
    if(S[0] == T[0]) for(int j = 0; j < m; j++) DP[j] = 1;
    else for(int j = 0; j < m; j++) DP[j] = 0;
    for(int j = 0; j < m; j++) P[0][j] = true;
    for(int i = 1; i < n; i++)
    {
        int DP2[m];
        DP2[0] = DP[0];
        if(S[i] == T[0]) DP2[0] = 1;
        for(int j = 1; j < m; j++)
        {
            if(S[i] == T[j]) DP2[j] = DP[j-1] + 1;
            else
            {
                if(DP2[j-1] > DP[j]) P[i][j] = true;
                DP2[j] = max(DP2[j-1], DP[j]);
            }
        }
        for(int j = 0; j < m; j++) DP[j] = DP2[j];
    }
    vector <char> ans;
    int x = m-1;
    int y = n-1;
    while(x >= 0 && y >= 0)
    {
        if(S[y] == T[x])
        {
            ans.pb(S[y]);
            x--;y--;
        }
        else if(P[y][x]) x--;
        else y--;
    }
    for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
}
