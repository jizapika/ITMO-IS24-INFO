#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("knapsack.in", "r", stdin);
    freopen("knapsack.out", "w", stdout);
    int s, n;
    cin >> s >> n;
    int DP[s+1];
    int A[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    sort(A, A + n);
    for(int j = 0; j <= s; j++) DP[j] = 0;
    DP[0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = s; j >= A[i]; j--)
        {
            DP[j] = max(DP[j], DP[j - A[i]]);
        }
    }
    int ma = 0;
    for(int j = 0; j <= s; j++) if(DP[j]) ma = j;
    cout << ma;
}
