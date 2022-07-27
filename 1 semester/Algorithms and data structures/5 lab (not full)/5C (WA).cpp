#include<iostream>
using namespace std;
int n;
void ins(int x, int A[], int L[], int R[])
{
    if(n==0){A[0]=x;L[0]=0;R[0]=0;return;}
    int cur=0;
    while(A[cur]!=x&&(L[cur]||R[cur]))
    {
        if(x<A[cur]&&L[cur])cur=L[cur];
        else if(x>A[cur]&&R[cur]) cur=R[cur];
        else break;
    }
    if(A[cur]!=x)
    {
        if(x>A[cur])
        {
            R[cur]=n;
            A[n]=x;
            L[n]=0;
            R[n]=0;
        }
        else
        {
            L[cur]=n;
            A[n]=x;
            L[n]=0;
            R[n]=0;
        }
    }
}
void mov(int pos1, int pos2, int A[], int L[], int R[])
{

    if(A[pos1]<A[pos2])
    {
        L[pos2]=L[pos1];
    }
    else
    {
        R[pos2]=R[pos1];
    }
    A[pos2]=A[pos1];
    if(L[pos1])
    {
        mov(L[pos1], pos1, &A[0], &L[0], &R[0]);
    }
    else if(R[pos1])
    {
        mov(R[pos1], pos1, &A[0], &L[0], &R[0]);
    }

}
void del(int x, int A[], int L[], int R[])
{
    int cur=0;
    int p=-1;
    while(A[cur]!=x&&(L[cur]||R[cur]))
    {
        p=cur;
        if(x<A[cur]&&L[cur])cur=L[cur];
        else if(x>A[cur]&&R[cur]) cur=R[cur];
        else break;
    }
    if(A[cur]==x)
    {
        if(p==-1)
        {
            if(L[cur])
            {
                mov(L[cur], cur, &A[0], &L[0], &R[0]);
            }
            else if(R[cur])
            {
                mov(R[cur], cur, &A[0], &L[0], &R[0]);
            }
            else n=0;
        }
        else if(L[cur]&&R[cur])
        {
            if(p>A[cur])
            {
                A[cur]=A[R[cur]];
                R[cur]=0;
            }
            else
            {
                A[cur]=A[L[cur]];
                L[cur]=0;
            }
        }
        else if(L[cur])
        {
            if(A[p]>A[cur])L[p]=L[cur];
            else R[p]=L[cur];
        }
        else if(R[cur])
        {
            if(A[p]>A[cur])L[p]=R[cur];
            else R[p]=R[cur];
        }
        else
        {
            if(A[p]>A[cur])L[p]=0;
            else R[p]=0;
        }
    }
}
string exi(int x, int A[], int L[], int R[])
{
    if(n==0)return "false";
    int cur=0;
    while(A[cur]!=x&&(L[cur]||R[cur]))
    {
        if(x<A[cur]&&L[cur])cur=L[cur];
        else if(x>A[cur]&&R[cur]) cur=R[cur];
        else break;
    }
    if(A[cur]==x)return "true";
    else return "false";
}
int nex(int x, int A[], int L[], int R[])
{
    if(n==0)return 1000000001;
    int cur=0;
    int mi=1000000001;
    while(L[cur]||R[cur])
    {
        if(A[cur]>x)mi=min(mi,A[cur]);
        if(x<A[cur]&&L[cur]||!(R[cur]))cur=L[cur];
        else cur=R[cur];
    }
    if(A[cur]>x)mi=min(mi,A[cur]);
    return mi;
}
int pre(int x, int A[], int L[], int R[])
{
    if(n==0)return -1000000001;
    int cur=0;
    int ma=-1000000001;
    while(L[cur]||R[cur])
    {
        if(A[cur]<x)ma=max(ma,A[cur]);
        if(x<A[cur]&&L[cur]||!(R[cur]))cur=L[cur];
        else cur=R[cur];
    }
    if(A[cur]<x)ma=max(ma,A[cur]);
    return ma;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);
    n=0;
    int A[100001],L[100001],R[100001];
    string S;
    while(cin>>S)
    {
        int x;
        cin>>x;
        if(S[0]=='i')
        {
            ins(x, &A[0], &L[0], &R[0]);
            n++;
        }
        if(S[0]=='d')
        {
            del(x, &A[0], &L[0], &R[0]);
        }
        if(S[0]=='e')
        {
            cout<<exi(x, &A[0], &L[0], &R[0])<<endl;
        }
        if(S[0]=='n')
        {
            if(nex(x, &A[0], &L[0], &R[0])!=1000000001)cout<<nex(x, &A[0], &L[0], &R[0])<<endl;
            else cout<<"none"<<endl;
        }
        if(S[0]=='p')
        {
            if(pre(x, &A[0], &L[0], &R[0])!=-1000000001)cout<<pre(x, &A[0], &L[0], &R[0])<<endl;
            else cout<<"none"<<endl;
        }
    }
}
/*
i 8
i 12
i 14
i 15
i 10
i 4
i 6
i 8
i 17
i 3
i 18
i 25
i 22
i 23
i 24
i 26
prev 23
e 23
e 22
e 21
*/
