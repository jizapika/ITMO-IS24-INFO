#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++)cin>>A[i];
    int m;
    cin>>m;
    int B[m];
    for(int i=0; i<m; i++)
    {
        cin>>B[i];
        if(B[i]<A[0]||B[i]>A[n-1])cout<<"-1 -1"<<endl;
        else
        {
            int l=-1,r=n;
            while(r-l>1)
            {
                int m=(r+l)/2;
                if(A[m]<B[i])l=m;
                else r=m;
            }
            if(A[r]!=B[i])cout<<"-1 -1"<<endl;
            else
            {
                cout<<r+1<<" ";
                l=-1;r=n;
                while(r-l>1)
                {
                    int m=(r+l)/2;
                    if(A[m]>B[i])r=m;
                    else l=m;
                }
                cout<<r<<endl;
            }
        }
   }
    return 0;
}
