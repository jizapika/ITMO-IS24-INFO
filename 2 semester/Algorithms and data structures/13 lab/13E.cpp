#include<bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
struct bor_vertex
{
    char c;
    bool is_in_dictionary;
    vector<int> link_to_next;
    int prev_link;
    int suff_link;
    bool is_substring;
};
void Bor_Push(vector <bor_vertex> &Bor, const string &word)
{
    int cur = 0;
    for(int i = 0; i < word.length(); i++)
    {
        bool is_breaking = false;
        for(int j = 0; j < Bor[cur].link_to_next.size(); j++)
        {
            if(Bor[Bor[cur].link_to_next[j]].c == word[i])
            {
                cur = Bor[cur].link_to_next[j];
                is_breaking = true;
                break;
            }
        }
        if(!is_breaking)
        {
            bor_vertex new_string;
            Bor[cur].link_to_next.pb(Bor.size());
            new_string.c = word[i];
            new_string.is_in_dictionary = false;
            new_string.prev_link = cur;
            cur = Bor.size();
            new_string.suff_link = 0;
            new_string.is_substring = false;
            Bor.pb(new_string);
        }
    }
    Bor[cur].is_in_dictionary = true;
    return;
}
void make_suff_link(int cur, vector <bor_vertex> &Bor)
{
    int new_suff_link = Bor[Bor[cur].prev_link].suff_link;
    int new_suff_link_checker_antycycle = 0;
    while(true)
    {
        bool is_breaking = false;
        for(int j = 0; j < Bor[new_suff_link].link_to_next.size(); j++)
        {
            if(Bor[Bor[new_suff_link].link_to_next[j]].c == Bor[cur].c)
            {
                if(Bor[new_suff_link].link_to_next[j] == cur) new_suff_link = 0;
                else new_suff_link = Bor[new_suff_link].link_to_next[j];
                is_breaking = true;
                break;
            }
        }
        if(new_suff_link == 0) break;
        if(is_breaking) break;
        new_suff_link = Bor[new_suff_link].suff_link;
    }
    Bor[cur].suff_link = new_suff_link;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    ;
}
void bfs_suff_link(int cur, vector <bor_vertex> &Bor)
{
    queue<int> q;
    q.push(cur);
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        make_suff_link(cur, Bor);
        for(int j = 0; j < Bor[cur].link_to_next.size(); j++)
        {
            q.push(Bor[cur].link_to_next[j]);
        }
    }
}
void bfs_upper(vector<bor_vertex> &Bor)
{
    bool used[Bor.size()];
    for(int b = 0; b < Bor.size(); b++) used[b] = false;
    for(int b = 0; b < Bor.size(); b++) if(Bor[b].is_substring)
    {
        queue<int> q;
        q.push(b);
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            Bor[cur].is_substring = true;
            used[cur] = true;
            if(!used[Bor[cur].prev_link] && !Bor[Bor[cur].prev_link].is_substring)
            {
                q.push(Bor[cur].prev_link);
                used[Bor[cur].prev_link] = true;
            }
            if(!used[Bor[cur].suff_link] && !Bor[Bor[cur].suff_link].is_substring)
            {
                q.push(Bor[cur].suff_link);
                used[Bor[cur].suff_link] = true;
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("search4.in", "r", stdin);
    freopen("search4.out", "w", stdout);
    int str;
    cin >> str;
    string S[str];
    vector <bor_vertex> Bor;
    bor_vertex empty_string;
    empty_string.c = '#';
    empty_string.is_in_dictionary = false;
    empty_string.prev_link = 0;
    empty_string.suff_link = 0;
    empty_string.is_substring = false;
    Bor.pb(empty_string);
    for(int s = 0; s < str; s++)
    {
        cin >> S[s];
        Bor_Push(Bor, S[s]);
    }
    bfs_suff_link(0, Bor);
    string T;
    cin >> T;
    int cur = 0;
    for(int i = 0; i < T.length(); i++)
    {
        bool is_breaking = false;
        for(int j = 0; j < Bor[cur].link_to_next.size(); j++)
        {
            if(Bor[Bor[cur].link_to_next[j]].c == T[i])
            {
                cur = Bor[cur].link_to_next[j];
                is_breaking = true;
                break;
            }
        }
        if(!is_breaking)
        {
            cur = Bor[cur].suff_link;
            int cur_checker_antycycle = 0;
            while(true)
            {
                Bor[cur].is_substring = true;
                bool is_breaking = false;

                for(int j = 0; j < Bor[cur].link_to_next.size(); j++)
                {
                    if(Bor[Bor[cur].link_to_next[j]].c == T[i])
                    {
                        cur = Bor[cur].link_to_next[j];
                        is_breaking = true;
                        break;
                    }
                }
                if(cur == 0) cur_checker_antycycle++;
                if(cur_checker_antycycle == 3) break;
                if(is_breaking) break;
                cur = Bor[cur].suff_link;
            }

        }
   //     cout << i+1 << " symbol of T, and " << cur << " position " << endl;
        Bor[cur].is_substring = true;
    }
    bfs_upper(Bor);
    for(int s = 0; s < str; s++)
    {
        int cur = 0;
        for(int i = 0; i < S[s].length(); i++)
        {
            for(int j = 0; j < Bor[cur].link_to_next.size(); j++)
            {
                if(Bor[Bor[cur].link_to_next[j]].c == S[s][i])
                {
                    cur = Bor[cur].link_to_next[j];
                    break;
                }
            }
        }
  //      cout << S[s] << " ";
        if(Bor[cur].is_substring) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    /*cout << "----------------------" << endl;
    cout << "BOR: " << endl;
    for(int i = 0; i < Bor.size(); i++)
    {
        cout << i << ") ";
        cout << "letter = " << Bor[i].c;
        cout << "; nexts: "; for(int j = 0; j < Bor[i].link_to_next.size(); j++) cout << Bor[i].link_to_next[j] << " ";
        cout << endl;
        if(Bor[i].is_in_dictionary) cout << "In dictionary and ";
        else cout << "Not in dictionary and ";
        if(Bor[i].is_substring) cout << "is substring";
        else cout << "isn't substring";
        cout << endl;
        cout << "suff: " << Bor[i].suff_link << " and prev: " << Bor[i].prev_link << endl;
    }*/
}
/*
5
ababc
cabab
ab
bac
cab
abababcabcaba

5
abbab
baba
aabb
abaab
bbbaa
aababbbababbaab

100
1328
95130
73
62583
7012
75219
54817
7401
217
4208
8234
54910
2938
82143
7123
01873
3429
86
278
26470
8372
081
25
1493
98704
71693
80
025
13
0581
25
14932
3476
376
32876
061
70
54
37586
79
92640
691
52
95736
29
4230
9810
86479
389
503
136
27419
017
724
2706
7652
63028
0712
382
69537
169
81
30
93
35649
865
07569
3961
02
827
094
06183
7428
21
69543
65219
79
35
13095
9306
82
7546
35
826
215
850
765
40
14
04
0823
156
678
130
7956
79
30
71625
10647
028
3200585732115062515867380397035829508783720840893453254967017785228995753734215925435583947136792836492205759418232380883421046706351531304859808360460913193526712277326961675133807813844479615484946238009782648537017728216764731818455122555873384385764714

5
abbab
baaba
ababb
babaa
abbba
ababababbababababbabsababababsbbbbabababbaabbababab
*/
