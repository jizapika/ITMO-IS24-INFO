#include<iostream>
#include<map>
#define int long long
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    int DP[n][n];
    for(int i = 0; i < n; i++) DP[i][i] = 1;
    for(int d = 1; d < n; d++)
    {
        for(int b = 0; b + d < n; b++)
        {
            DP[b][b+d] = DP[b+1][b+d] + DP[b][b+d-1] + 1;
            if(A[b] != A[b+d]) DP[b][b+d]--;
            if(A[b] != A[b+d] && d > 1) DP[b][b+d] -= DP[b+1][b+d-1] - 2000000000;
            DP[b][b+d] %= 1000000000;
        }
    }
    cout << DP[0][n-1];
}
