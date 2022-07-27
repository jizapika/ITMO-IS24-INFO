#include<iostream>
#include<vector>
#define int long long
using namespace std;
int N1 = 1903, N2 = 300;
vector<vector<vector<vector<string> > > > A;
string B[1903][100];
int Hashf1(string a)
{
    int p = 127;
    int k = 0;
    for(int i = 0; i < a.size(); i++)
    {
        k *= p;
        k += a[i] - '0';
        k = max(k, -k);
        k %= N1;
    }
    return k;
}
int Hashf2(string a)
{
    int p = 127;
    int k = 0;
    for(int i = 0; i < a.size(); i++)
    {
        k *= p;
        k += a[i] - '0';
        k = max(k, -k);
        k %= N2;
    }
    return k;
}
void put(string First, string Second)
{
    int pos1 = Hashf1(First);
    for(int j = 0; j < 100; j++) if(B[pos1][j] == First)
    {
        int pos2 = Hashf2(Second);
        for(int k = 0; k < A[pos1][j][pos2].size(); k++) if(A[pos1][j][pos2][k] == Second)
        {
            return;
        }
        A[pos1][j][pos2].push_back(Second);
        return;
    }
    for(int j = 0; j < 100; j++) if(B[pos1][j] == "")
    {
        B[pos1][j] = First;
        A[pos1][j].resize(N2);
        int pos2 = Hashf2(Second);
        for(int k = 0; k < A[pos1][j][pos2].size(); k++) if(A[pos1][j][pos2][k] == Second)
        {
            return;
        }
        A[pos1][j][pos2].push_back(Second);
        return;
    }
}
void del(string First, string Second)
{
    int pos1 = Hashf1(First);
    for(int j = 0; j < 100; j++) if(B[pos1][j] == First)
    {
        int pos2 = Hashf2(Second);
        for(int k = 0; k < A[pos1][j][pos2].size(); k++) if(A[pos1][j][pos2][k] == Second)
        {
            vector<string> R;
            for(int z = 0; z < A[pos1][j][pos2].size(); z++) if(A[pos1][j][pos2][z] != Second) R.push_back(A[pos1][j][pos2][z]);
            A[pos1][j][pos2] = R;
            return;
        }
        return;
    }
}
void delall(string First)
{
    int pos1 = Hashf1(First);
    for(int j = 0; j < 100; j++) if(B[pos1][j] == First)
    {
        B[pos1][j] = "";
        A[pos1][j].clear();
        return;
    }
}
vector<string> get(string First)
{
    vector<string> ans;
    int pos1 = Hashf1(First);
    for(int j = 0; j < 100; j++) if(B[pos1][j] == First)
    {
        for(int pos2 = 0; pos2 < N2; pos2++)
        {
            for(int k = 0; k < A[pos1][j][pos2].size(); k++) ans.push_back(A[pos1][j][pos2][k]);
        }
        return ans;
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("multimap.in", "r", stdin);
    freopen("multimap.out", "w", stdout);
    A.resize(N1);
    for(int i = 0; i < N1; i++) A[i].resize(100);
    for(int i = 0; i < N1; i++) for(int j = 0; j < 100; j++) B[i][j] = "";
    string S;
    while(cin >> S)
    {
        string X;
        cin >> X;
        if(S == "put")
        {
            string Y;
            cin >> Y;
            put(X, Y);
        }
        if(S == "delete")
        {
            string Y;
            cin >> Y;
            del(X, Y);
        }
        if(S == "deleteall")
        {
            delall(X);
        }
        if(S == "get")
        {
            vector<string>ans;
            ans = get(X);
            cout << ans.size() << " ";
            for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
            cout << endl;
        }
    }
}
