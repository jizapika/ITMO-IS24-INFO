#include<iostream>
using namespace std;
bool comprasion (string A, string B)
{
    int y=0;
    while(y<min(A.length(),B.length()))
    {
        if(A[y]<B[y])return 0;
        if(A[y]>B[y])return 1;
        y++;
    }
    return (A.length()>B.length());
}
bool cmp(pair<string,string> a, pair<string,string> b)
{
    return (comprasion(a.first,b.first));
}
void mgsort(int n, pair<string,string> A[])
{
    int k=1;
    while(k<n)
    {
        for(int i=0; i<(n/k+1)/2; i++)
        {
            int m = min(k,n-(2*i+1)*k);
            pair<string,string> B[k+m];
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
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int n;
    cin>>n;
    pair < string , string > A[n];
    for(int i=0; i<n; i++)
    {
        string S,T;
        cin>>S>>T;
        A[i] = {S, T};
    }
    mgsort( n, &A[0] );
    for(int i=0; i<n; i++)
    {
        if(i==0||A[i].first!=A[i-1].first)
        {
            cout<<"=== "<<A[i].first<<" ==="<<endl;
        }
        cout<<A[i].second<<endl;
    }
}
