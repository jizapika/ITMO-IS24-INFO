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
void solve()
{
    int n, m;
    cin >> n >> m;
    int A[n][n];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) A[i][j] = 0;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        A[a-1][b-1] ++;
    }
    int t = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < i; j++) if(A[i][j] + A[j][i] >= 2) t = 1;
    if(t) cout << "YES";
    else cout << "NO";
}
signed main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)solve();
}
