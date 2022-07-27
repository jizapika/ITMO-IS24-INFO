#include<iostream>
#include<map>
#define int long long
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);
    int n, s, f;
    cin >> n >> s >> f;
    s--; f--;
    int A[n][n];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> A[i][j];
    int D[n];
    for(int i = 0; i < n; i++) D[i] = 2000000000000000;
    D[s] = 0;
    int Used[n];
    for(int i = 0; i < n; i++) Used[i] = 0;
    while(true)
    {
        int mi = 1000000000000000, pos = -1;
        for(int j = 0; j < n; j++) if(!Used[j]) if(mi > D[j])
        {
            mi = D[j];
            pos = j;
        }
        if(pos == -1) break;
        Used[pos] = 1;
        for(int j = 0; j < n; j++) if(A[pos][j] != -1) if(D[j] > D[pos] + A[pos][j])
        {
            D[j] = D[pos] + A[pos][j];
        }
    }
    if(D[f] < 2000000000000000) cout << D[f];
    else cout << -1;
}
