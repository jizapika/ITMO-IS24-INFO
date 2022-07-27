#include<iostream>
using namespace std;
bool cmp(int a, int b)
{
    return a>b;
}
void mgsort(int n, int A[])
{

    int k=1;
    while(k<n)
    {
        for(int i=0; i<(n/k+1)/2; i++)
        {
            int m= min(k,n-(2*i+1)*k);
            int B[k+m];
            int s=0;
            int i1=2*i*k,i2=(2*i+1)*k;
            while(i1<(2*i+1)*k||i2<(2*i+1)*k+m)
            {
                if(i1==(2*i+1)*k){B[s]=A[i2];i2++;}
                else if(i2==(2*i+1)*k+m){B[s]=A[i1];i1++;}
                else
                {
                    if(cmp(A[i1],A[i2])){B[s]=A[i2]; i2++;}
                    else {B[s]=A[i1];i1++;}
                }
                s++;
            }
            for(int j=0; j<k+m; j++)A[j+2*i*k]=B[j];
        }
        k=k*2;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++)cin>>A[i];
    mgsort(n, &A[0]);
    for(int i=0; i<n; i++)cout<<A[i]<<" ";
    cout<<endl;
}
/*
7
1 3 -1 -3 7 -7 0
*/
