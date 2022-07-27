#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);
    int n;
    cin>>n;
    if(n==0){cout<<0; return 0;}
    int H[n];
    for(int i=0; i<n; i++)H[i]=1000000;
    H[0]=0;
    int P[n];
    int ma=0;
    for(int i=0; i<n; i++)
    {
        int k,l,r;
        cin>>k>>l>>r;
        if(l)H[l-1]=H[i]+1;
        if(r)H[r-1]=H[i]+1;
        ma=max(ma,H[i]);
    }
    cout<<ma+1<<endl;
}
