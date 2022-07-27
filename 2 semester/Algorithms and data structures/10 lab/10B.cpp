#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define vp vector<pii>
using namespace std;
double Length(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}
void solve()
{
    int n;
    cin >> n;
    double X[n], Y[n];
    for(int i = 0; i < n; i++)
    {
        cin >> X[i] >> Y[i];
    }
    if(n == 1) cout << 0;
    else
    {
        double MI[n];
        MI[0] = -1;
        for(int j = 1; j < n; j++) MI[j] = Length(X[0], Y[0], X[j], Y[j]);
        double length = 0;
        int pos;
        while(true)
        {
            double mi = 1000000;
            for(int i = 0; i < n; i++) if(MI[i] != -1 && MI[i] < mi)
            {
                mi = MI[i];
                pos = i;
            }
            if(mi == 1000000) break;
            length += MI[pos];
            MI[pos] = -1;
            for(int j = 0; j < n; j++) MI[j] = min(MI[j], Length(X[pos], Y[pos], X[j], Y[j]));
        }
        cout << setprecision(13) << length;
    }
}
signed main()
{
    freopen("spantree.in", "r", stdin);
    freopen("spantree.out", "w", stdout);
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)solve();
}
