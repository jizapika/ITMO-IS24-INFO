#include<bits/stdc++.h>
#include<string>
#define int long long
#define f first
#define s second
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);
    int n;
    cin>>n;
    int L[n];
    int R[n];
    int A[n];
    for(int i=0; i<n; i++)
    {
        cin>>A[i]>>L[i]>>R[i];
    }
    int D[n];
    for(int i=0; i<n; i++)D[i] = 1;
    int ANS[n];
    for(int i=n-1; i>=0; i--)
    {
        L[i]--;
        R[i]--;
        if(L[i] == -1 && R[i] == -1) ANS[i] = 0;
        else if(L[i] == -1)
        {
            ANS[i] = D[R[i]];
            D[i] = 1 + D[R[i]];
        }
        else if(R[i] == -1)
        {
            ANS[i] = -D[L[i]];
            D[i] = 1 + D[L[i]];
        }
        else
        {
            ANS[i] = D[R[i]] - D[L[i]];
            D[i] = 1 + max(D[L[i]],D[R[i]]);
        }
    }
    for(int i=0; i<n; i++) cout << ANS[i] << endl;
}
