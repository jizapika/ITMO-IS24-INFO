#include<iostream>
using namespace std;
bool cmp(int a, int b)
{
    return (a<b);
}
void add(int x, int A[], int newsize)
{
    A[newsize]=x;
    while(newsize)
    {
        if(cmp(A[newsize],A[(newsize-1)/2]))swap(A[newsize],A[(newsize-1)/2]);
        newsize=(newsize-1)/2;
    }
}
int put_vertex(int A[], int lastnum)
{
    int res=A[0];
    A[0]=A[lastnum];
    int used=0;
    while((used*2+1<lastnum&&!cmp(A[used],A[used*2+1]))||(used*2+2<lastnum&&!cmp(A[used],A[used*2+2])))
    {
        if(used*2+2<lastnum&&cmp(A[used*2+1],A[used*2+2]))
        {
            swap(A[used],A[used*2+1]);
            used=used*2+1;
        }
        else if(used*2+2<lastnum&&cmp(A[used*2+2],A[used*2+1]))
        {
            swap(A[used],A[used*2+2]);
            used=used*2+2;
        }
        else
        {
            swap(A[used],A[used*2+1]);
            used=used*2+1;
        }
    }
    return res;
}
void beginn()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++)cin>>A[i];
    for(int i=0; i<n; i++)add(A[i],&A[0],i);
    for(int i=0; i<n; i++)cout<<put_vertex(&A[0],n-i-1)<<" ";
}
int main()
{
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--)beginn();
    return 0;
}
/*
20
20 19 18 71 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
*/
