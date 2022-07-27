#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define f first
#define s second
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //  freopen("prefix.in", "r", stdin);
    //freopen("prefix.out", "w", stdout);
    int c;
    cin >> c;
    string S;
    cin >> S;
    int n = S.length();
    int A[n+1][c];
    int Last[c];
    for(int j = 0; j < c; j++)
    {
        if(S[0] - 'a' == j) A[0][j] = 1;
        else A[0][j] = 0;
    }
    int cur = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(S[i] - 'a' == j) A[i][j] = i + 1;
            else A[i][j] = A[cur][j];
        }
        cur = A[cur][S[i] - 'a'];
    }
    for(int j = 0; j < c; j++)
    {
        A[n][j] = A[cur][j];
    }
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j < c; j++) cout << A[i][j] << " ";
        cout << endl;
    }
}
/*
2
abbabaab
*/
