#include<iostream>
#include<vector>
#define int long long
using namespace std;
int N=39438;
vector<vector<int> >HashTable;
int Hashfunction(int a)
{
    a = abs(a);
    a %= N;
    return a;
}
bool finder(int a)
{
    int pos = Hashfunction(a);
    int t=0;
    for(int i=0; i<HashTable[pos].size(); i++)if(HashTable[pos][i] == a)t=1;
    return t;
}
void eraser(int a)
{
    int pos = Hashfunction(a);
    vector<int>k;
    for(int i=0; i<HashTable[pos].size(); i++)k.push_back(HashTable[pos][i]);
    HashTable[pos].clear();
    for(int i=0; i<k.size(); i++)if(k[i]!=a)HashTable[pos].push_back(k[i]);
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    string S;
    HashTable.resize(N);
    while(cin>>S)
    {
        int n;
        cin>>n;
        if(S[0]=='i')
        {
            if(!(finder(n))) HashTable[Hashfunction(n)].push_back(n);
        }
        else if(S[0]=='e')
        {
            if(finder(n))cout<<"true"<<endl;
            else cout<<"false"<<endl;
        }
        else eraser(n);
    }
}
