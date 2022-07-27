#include<bits/stdc++.h>
#define ll long long
#define int long long
#define pb push_back
#define pii pair<int,int>
#define piii pair<pii,int>
#define f first
#define s second
#define vi vector<int>
using namespace std;
void beginn()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++)cin>>A[i];
    int t=1;
    for(int i=1; i<=n; i++)
    {
        if(2*i<=n&&A[2*i-1]<A[i-1])t=0;
        if(2*i+1<=n&&A[2*i]<A[i-1])t=0;
    }
    if(t)cout<<"YES";
    else cout<<"NO";
}
signed main()
{
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--)beginn();
    return 0;
}
