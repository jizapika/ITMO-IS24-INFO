#include<iostream>
#include<map>
#define int long long
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("knight2.in", "r", stdin);
    freopen("knight2.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int DP[n][m];
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) DP[i][j] = 0;
    DP[0][0] = 1;
    for(int i = 0; i < n + m + 1; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            int x = i - j;
            int y = j;
            if(x < n && y < m)
            {
                if(x+1 < n && y > 1) DP[x][y] += DP[x+1][y-2];
                if(x > 1 && y+1 < m) DP[x][y] += DP[x-2][y+1];
                if(x && y > 1) DP[x][y] += DP[x-1][y-2];
                if(x > 1 && y) DP[x][y] += DP[x-2][y-1];
            }
        }
    }
    cout << DP[n-1][m-1];
}
