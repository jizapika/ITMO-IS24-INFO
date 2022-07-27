#include<iostream>
#include<string>
#define int long long
#define f first
#define s second
using namespace std;
int N = 33347;
int p = 903404987;
pair <string, string> HashTable[33347][100];
int Hashfunction(string a)
{
    int res = 0;
    for(int i = 0; i < a.length(); i++)
    {
        res *= 239;
        res += a[i] - '0';
        res %= p;
    }
    res %= N;
    return res;
}
string finder(string a)
{
    int pos = Hashfunction(a);
    int t = 0;
    for(int i = 0; i < 100; i++) if(HashTable[pos][i].f == a)
    {
        return HashTable[pos][i].s;
    }
    return "none";
}
void eraser(string a)
{
    int pos = Hashfunction(a);
    for(int i = 0; i < 100; i++) if(HashTable[pos][i].f == a) HashTable[pos][i].f = "jidewjoei";
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
    string S;
    for(int i = 0; i < N; i++) for(int j = 0; j < 100; j++) HashTable[i][j] = {"jidewjoei","jidewjoei"};
    while(cin>>S)
    {
        string A;
       	cin >> A;
        if(S[0] == 'p')
        {
        	string B;
    		cin >> B;
            int r = 1;
            for(int i = 0; i < 100; i++) if(HashTable[Hashfunction(A)][i].f == A)
            {
                HashTable[Hashfunction(A)][i].f = A;
                HashTable[Hashfunction(A)][i].s = B;
                r = 0;
                break;
            }
            if(r)
            {
                for(int i = 0; i < 100; i++) if(HashTable[Hashfunction(A)][i].f == "jidewjoei")
                {
                    HashTable[Hashfunction(A)][i].f = A;
                    HashTable[Hashfunction(A)][i].s = B;
                    break;
                }
            }
        }
        else if(S[0] == 'g')
        {
            cout<< finder(A) <<endl;
        }
        else
        {
        	eraser(A);
        }
    }
}
