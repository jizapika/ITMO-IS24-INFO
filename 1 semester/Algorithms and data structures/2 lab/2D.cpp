#include<iostream>
using namespace std;
int main()
{
    freopen("antiqs.in", "r", stdin);
    freopen("antiqs.out", "w", stdout);
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++)A[i]=i+1;
    for(int i=1; i<n; i++)swap(A[i/2],A[i]);
    for(int i=0; i<n; i++)cout<<A[i]<<" ";
}
