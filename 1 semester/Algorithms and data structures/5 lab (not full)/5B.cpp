#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
    int n;
    cin>>n;
    if(n==0){cout<<"YES"; return 0;}
    int A[n];
    int L[n];
    int R[n];
    int MA[n];
    int MI[n];
    for(int i=0; i<n; i++)cin>>A[i]>>L[i]>>R[i];
    for(int i=0; i<n; i++)MA[i]=1000000001;
    for(int i=0; i<n; i++)MI[i]=-1000000001;
    int t=1;
    for(int i=0; i<n; i++)
    {
        if(L[i])
        {
            MA[L[i]-1]=min(MA[i],A[i]);
            MI[L[i]-1]=MI[i];
        }
        if(R[i])
        {
            MI[R[i]-1]=max(MI[i],A[i]);
            MA[R[i]-1]=MA[i];
        }
        if(A[i]>=MA[i])t=0;
        if(A[i]<=MI[i])t=0;
    }
    if(t)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
