#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define f first
#define s second
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    string A;
    cin >> A;
    int n = A.length();
    int P[n];
    P[0] = 0;
    for(int i = 1; i < n; i++)
    {
        int k = P[i-1];
        while(k > 0)
        {
            if(A[i] == A[k])
            {
                P[i] = k+1;
                break;
            }
            k = P[k-1];
        }
        if(k == 0)
        {
            if(A[i] != A[0]) P[i] = 0;
            else P[i] = 1;
        }
    }
    for(int i = 0; i < n; i++) cout << P[i] << " ";
}
/*
abaabbabaaba
001120123453
*/
