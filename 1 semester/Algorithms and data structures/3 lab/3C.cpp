#include<iostream>
using namespace std;
void beginn()
{
    int n,m,k;
    cin>>n>>m>>k;
    int A[26][n];
    int I[26];
    string S[n];
    for(int i=0; i<n; i++)cin>>S[i];
    string J[n];
    for(int j=m-1; j>=m-k; j--)
    {
        for(int q=0; q<26; q++)for(int i=0; i<n; i++)A[q][i]=-1;
        for(int q=0; q<26; q++)I[q]=0;
        for(int i=0; i<n; i++)
        {
            A[S[i][j]-'a'][I[S[i][j]-'a']]=i;
            I[S[i][j]-'a']++;
        }
        for(int i=0; i<n; i++)J[i]=S[i];
        int pos=0;
        for(int q=0; q<26; q++)for(int i=0; i<n; i++)if(A[q][i]!=-1)
        {
            S[pos]=J[A[q][i]];
            pos++;
        }
    }
    for(int i=0; i<n; i++)cout<<S[i]<<endl;
}
int main()
{
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--)beginn();
    return 0;
}
