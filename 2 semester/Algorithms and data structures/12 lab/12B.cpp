#include<bits/stdc++.h>

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define f first
#define s second
#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 //   freopen("knapsack.in", "r", stdin);
   // freopen("knapsack.out", "w", stdout);
    int n;
    cin >> n;
    int A[n], DP[n+1], pos[n+1], prev[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    DP[0] = -1000000001;
    for(int i = 1; i <= n; i++) DP[i] = 1000000001;
    for(int i = 0; i < n; i++) prev[i] = -1;
    for(int i = 0; i < n; i++) pos[i] = -1;
    for(int i = 0; i < n; i++)
    {
        int l = -1, r = n;
        while(r - l > 1)
        {
            int m = (l+r)/2;
            if(DP[m] < A[i]) l = m;
            else r = m;
        }
        DP[r] = A[i];
        pos[r] = i;
        prev[i] = pos[r-1];
    }
    for(int i = n; i >= 0; i--) if(DP[i] != 1000000001)
    {
        cout << i << endl;
        vi ans;
        int p = pos[i];
        while(p != -1)
        {
            ans.pb(A[p]);
            p = prev[p];
        }
        for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
        return 0;
    }
}
