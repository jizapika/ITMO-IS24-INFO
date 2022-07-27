#include<iostream>
#define int long long
#define f first
#define s second
using namespace std;
int N = 6897;
pair<string, string> Table[6897][100];
string keys[100043];
int Unkeys[6897][100];
int numkey = 0, pastnumkey = -1;
pair<int, int> neighboursid[100043];
int hashf(string S)
{
    int k = 0;
    int p = 149;
    for(int i = 0; i < S.size(); i++)
    {
        k += S[i] - '0';
        k *= p;
        k = max(k, -k);
        k %= N;
    }
    return k;
}
void put(string key, string value)
{
    int id = hashf(key);
    for(int j = 0; j < 100; j++) if(Table[id][j].f == key)
    {
        Table[id][j].s = value;
        return;
    }
    for(int j = 0; j < 100; j++) if(Table[id][j].f == "")
    {
        Table[id][j] = {key, value};
        keys[numkey] = key;
        Unkeys[id][j] = numkey;
        neighboursid[numkey] = {pastnumkey, -1};
        neighboursid[pastnumkey].second = numkey;
        pastnumkey = numkey;
        numkey++;
        return;
    }
}
void del(string key)
{
    int id = hashf(key);
    for(int j = 0; j < 100; j++) if(Table[id][j].f == key)
    {
        Table[id][j] = {"",""};
        int num = Unkeys[id][j];
        if(num == pastnumkey)
        {
            pastnumkey = neighboursid[num].f;
        }
        if(neighboursid[num].f != -1)
        {
            neighboursid[neighboursid[num].f].s = neighboursid[num].s;
        }
        if(neighboursid[num].s != -1)
        {
            neighboursid[neighboursid[num].s].f = neighboursid[num].f;
        }
    }
}
string get(string key)
{
    int id = hashf(key);
    for(int j = 0; j < 100; j++) if(Table[id][j].f == key) return Table[id][j].s;
    return "none";
}
string prev(string key)
{
    int id = hashf(key);
    for(int j = 0; j < 100; j++) if(Table[id][j].f == key)
    {
        int num = Unkeys[id][j];
        int pos = neighboursid[num].f;
        if(pos != -1)
        {
            return get(keys[pos]);
        }
    }
    return "none";
}
string next(string key)
{
    int id = hashf(key);
    for(int j = 0; j < 100; j++) if(Table[id][j].f == key)
    {
        int num = Unkeys[id][j];
        int pos = neighboursid[num].s;
        if(pos != -1)
        {
            return get(keys[pos]);
        }
    }
    return "none";
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("linkedmap.in", "r", stdin);
    freopen("linkedmap.out", "w", stdout);
    for(int i = 0; i < N; i++) for(int j = 0; j < 100; j++) Table[i][j] = {"",""};
    for(int i = 0; i < N; i++) for(int j = 0; j < 100; j++) Unkeys[i][j] = -1;
    string S;
    while(cin >> S)
    {
        string x;
        cin >> x;
        if(S == "put")
        {
            string y;
            cin >> y;
            put(x, y);
        }
        if(S == "delete")
        {
            del(x);
        }
        if(S == "get")
        {
            cout << get(x) << endl;
        }
        if(S == "prev")
        {
            cout << prev(x) << endl;
        }
        if(S == "next")
        {
            cout << next(x) << endl;
        }
    }
}
