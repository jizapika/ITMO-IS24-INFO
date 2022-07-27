#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define f first
#define s second
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("search1.in", "r", stdin);
    freopen("search1.out", "w", stdout);
    string A, B;
    cin >> A >> B;
    vector<int> ans;
    if(B.length() < A.length()) {cout << 0; return 0;}
    for(int i = 0; i <= B.length() - A.length(); i++)
    {
        int t = 0;
        for(int j = i; j < i + A.length(); j++)
        {
            if(B[j] != A[j - i]) t = 1;
        }
        if(t == 0) ans.pb(i + 1);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
