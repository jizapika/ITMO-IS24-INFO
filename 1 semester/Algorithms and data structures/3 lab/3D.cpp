#include<iostream>
using namespace std;
bool cmp(int a, int b)
{
    return (a<b);
}
void add(int x, int A[], int newsize, int B[], int C[])
{
    A[newsize]=x;
    while(newsize)
    {
        if(cmp(A[newsize],A[(newsize-1)/2]))
        {
            swap(A[newsize],A[(newsize-1)/2]);
            swap(B[C[newsize]],B[C[(newsize-1)/2]]);
            swap(C[newsize],C[(newsize-1)/2]);
        }
        newsize=(newsize-1)/2;
    }
}
int put_vertex(int A[], int lastnum, int B[], int C[])
{
    int res=A[0];
    A[0]=A[lastnum];
    A[lastnum]=0;
    B[C[lastnum]]=0;
    C[0]=C[lastnum];
    int used=0;
    while((used*2+1<lastnum&&!cmp(A[used],A[used*2+1]))||(used*2+2<lastnum&&!cmp(A[used],A[used*2+2])))
    {
        if(used*2+2<lastnum&&cmp(A[used*2+1],A[used*2+2]))
        {
            swap(A[used],A[used*2+1]);
            swap(B[C[used]],B[C[used*2+1]]);
            swap(C[used],C[used*2+1]);
            used=used*2+1;
        }
        else if(used*2+2<lastnum&&cmp(A[used*2+2],A[used*2+1]))
        {
            swap(A[used],A[used*2+2]);
            swap(B[C[used]],B[C[used*2+2]]);
            swap(C[used],C[used*2+2]);
            used=used*2+2;
        }
        else
        {
            swap(A[used],A[used*2+1]);
            swap(B[C[used]],B[C[used*2+1]]);
            swap(C[used],C[used*2+1]);
            used=used*2+1;
        }
    }
    return res;
}
void decrease(int A[], int lastnum, int x, int y, int B[], int C[])
{
    if(cmp(A[B[x]],y))
    {
        A[B[x]]=y;
        int used=B[x];
        while((used*2+1<lastnum&&!cmp(A[used],A[used*2+1]))||(used*2+2<lastnum&&!cmp(A[used],A[used*2+2])))
        {
            if(used*2+2<lastnum&&cmp(A[used*2+1],A[used*2+2]))
            {
                swap(A[used],A[used*2+1]);
                swap(B[C[used]],B[C[used*2+1]]);
                swap(C[used],C[used*2+1]);
                used=used*2+1;
            }
            else if(used*2+2<lastnum&&cmp(A[used*2+2],A[used*2+1]))
            {
                swap(A[used],A[used*2+2]);
                swap(B[C[used]],B[C[used*2+2]]);
                swap(C[used],C[used*2+2]);
                used=used*2+2;
            }
            else
            {
                swap(A[used],A[used*2+1]);
                swap(B[C[used]],B[C[used*2+1]]);
                swap(C[used],C[used*2+1]);
                used=used*2+1;
            }
        }
    }
    else
    {
        A[B[x]]=y;
        int used=B[x];
        while(used)
        {
            if(cmp(A[used],A[(used-1)/2]))
            {
                swap(A[used],A[(used-1)/2]);
                swap(B[C[used]],B[C[(used-1)/2]]);
                swap(C[used],C[(used-1)/2]);
            }
            used=(used-1)/2;
        }
    }
}
void beginn()
{
    int A[1000010];
    int B[1000010];
    int C[1000010];
    string S;
    int summarysize=0;
    int numberstring=0;
    while(cin>>S)
    {
        numberstring++;
        B[numberstring]=0;
        if(S[0]=='p')
        {
            int x;
            cin>>x;
            C[summarysize]=numberstring;
            B[numberstring]=summarysize;
            add(x,&A[0],summarysize, &B[0], &C[0]);
            summarysize++;

        }
        if(S[0]=='e')
        {
            if(summarysize==0)cout<<'*'<<endl;
            else
            {
                summarysize--;
                cout<<put_vertex(&A[0],summarysize, &B[0], &C[0])<<endl;
            }
        }
        if(S[0]=='d')
        {
            int x,y;
            cin>>x>>y;
            decrease(&A[0],summarysize-1,x,y,&B[0],&C[0]);
            A[B[x]]=y;
        }
    }
}
int main()
{
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--)beginn();
    return 0;
}
