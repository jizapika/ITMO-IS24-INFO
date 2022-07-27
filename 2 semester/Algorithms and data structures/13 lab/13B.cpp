#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define f first
#define s second
using namespace std;
void Zfunction(string &S, int n, int *Z)
{
    Z[0] = 0;
    int l = 0, r = 0;
    for(int i = 1; i < n; i++)
    {
        if(i > r)
        {
            int y = i;
            while(y < n && S[y-i] == S[y]) y++;
            l = i;
            r = y-1;
            Z[i] = y-i;
        }
        else
        {
            if(Z[i-l] + i < r) Z[i] = Z[i-l];
            else
            {
                int y = r;
                while(y < n && S[y-i] == S[y]) y++;
                if(y > r)
                {
                    r = y;
                    l = i;
                    Z[i] = y-i;
                }
                else Z[i] = y-i;
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("search2.in", "r", stdin);
    freopen("search2.out", "w", stdout);
    string A, B;
    cin >> A >> B;
    if(B.length() < A.length()) {cout << 0; return 0;}
    vector<int> ans;
    string S = A + "#" + B;
    int Z[S.length()];
    Zfunction(S, S.length(), Z);
    for(int i = 0; i < S.length(); i++)
    {
        if(Z[i] == A.length()) ans.pb(i - A.length());
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
