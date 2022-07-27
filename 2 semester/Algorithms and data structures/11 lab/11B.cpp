#include<iostream>
#include<map>
#define int long long
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("pathsg.in", "r", stdin);
    freopen("pathsg.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int A[n][n];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) A[i][j] = -1;
    for(int i = 0; i < n; i++) A[i][i] = 0;
    while(m--)
    {
        int u, to, len;
        cin >> u >> to >> len;
        u--; to--;
        if(A[u][to] == -1 || A[u][to] > len) A[u][to] = len;
    }
    int D[n][n];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) D[i][j] = 2000000000000000;
    for(int i = 0; i < n; i++) D[i][i] = 0;
    for(int i = 0; i < n; i++)
    {
        int Used[n];
        for(int j = 0; j < n; j++) Used[j] = 0;
        while(true)
        {
            int mi = 1000000000000000, pos = -1;
            for(int j = 0; j < n; j++) if(!Used[j]) if(mi > D[i][j])
            {
                mi = D[i][j];
                pos = j;
            }
            if(pos == -1) break;
            Used[pos] = 1;
            for(int j = 0; j < n; j++) if(A[pos][j] != -1) if(D[i][j] > D[i][pos] + A[pos][j])
            {
                D[i][j] = D[i][pos] + A[pos][j];
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(D[i][j] < 2000000000000000) cout << D[i][j] << " ";
            else cout << -1 << " ";
        }
        cout << endl;
    }

}
