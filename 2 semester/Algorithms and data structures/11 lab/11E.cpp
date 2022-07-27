#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("negcycle.in", "r", stdin);
    freopen("negcycle.out", "w", stdout);
    int n;
    cin >> n;
    int A[n][n];
    int D[n];
    int P[n];
    for(int i = 0; i < n; i++) P[i] = -1;
    for(int j = 0; j < n; j++) D[j] = 1000000000;
    D[0] = 0;

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> A[i][j];
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n; j++) for(int k = 0; k < n; k++) if(D[k] > D[j] + A[j][k])
        {
            D[k] = D[j] + A[j][k];
            P[k] = j;
        }
    }
    for(int j = 0; j < n; j++) for(int k = 0; k < n; k++) if(D[k] > D[j] + A[j][k])
    {
        D[k] = D[j] + A[j][k];
        vector<int> ans;
        int s = j;
        ans.pb(k);
        while(s != k)
        {
            ans.pb(s);
            s = P[s];
            if(ans.size() > n) break;
        }
        if(ans.size() > n) continue;
        ans.pb(k);
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i] + 1 << " ";
        return 0;
    }
    cout << "NO" << endl;
}
