#include<bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;
void print_min_degree(const vector< vector<int> > &G, const vector<string> &Name)
{
    size_t mi = G.size();
    for(int i = 0; i < G.size(); i++) if(G[i].size()) mi = min(mi, G[i].size());
    cout << "min degree is: " << mi << "(    ";
    for(int i = 0; i < G.size(); i++) if(mi == G[i].size()) cout << Name[i] << "    ";
    cout << ")" << endl;
}
void print_max_degree(const vector< vector<int> > &G, const vector<string> &Name)
{
    size_t ma = 0;
    for(int i = 0; i < G.size(); i++) ma = max(ma, G[i].size());
    cout << "max degree is: " << ma << "(    ";
    for(int i = 0; i < G.size(); i++) if(ma == G[i].size()) cout << Name[i] << "    ";
    cout << ")" << endl;
}
void dfs_comp(int a, const vector< vector<int> > &G, vector<int> &comp)
{
    for(int i = 0; i < G[a].size(); i++) if(!comp[G[a][i]])
    {
        comp[G[a][i]] = comp[a];
        dfs_comp(G[a][i], G, comp);
    }
}
void fill_with_components(const vector< vector<int> > &G, vector<int> &comp)
{
    comp.clear();
    int n = G.size();
    comp.resize(n, 0);
    int num_comp = 0;
    for(int i = 0; i < n; i++) if(comp[i] == 0)
    {
        num_comp++;
        comp[i] = num_comp;
        dfs_comp(i, G, comp);
    }
}
vector< vector<int> > max_component(const vector< vector<int> > &G)
{
    vector< vector<int> > component(G.size());
    vector<int> fillcomp;
    fill_with_components(G, fillcomp);
    vector<int> component_size(G.size(), 0);
    for(int i = 0; i < G.size(); i++) component_size[fillcomp[i]]++;
    int ma = 0;
    for(int i = 0; i < G.size(); i++) ma = max(ma, component_size[i]);
    for(int i = 0; i < G.size(); i++) if(ma == component_size[i])
    {
        for(int i2 = 0; i2 < G.size(); i2++)
        {
            for(int j = 0; j < G[i2].size(); j++)
            {
                if(fillcomp[i2] == i && fillcomp[G[i2][j]] == i) component[i2].pb(G[i2][j]);
            }
        }
        break;
    }
    return component;
}
vector<int> excentres(const vector< vector<int> > &G)
{
    int n = G.size();
    vector<int> ex(n, 0);
    int D[n][n];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) D[i][j] = n;
    for(int i = 0; i < n; i++) if(G[i].size())
    {
        D[i][i] = 0;
        for(int x = 0; x < n; x++)
        {
            for(int j = 0; j < G.size(); j++)
            {
                for(int k = 0; k < G[j].size(); k++) D[i][G[j][k]] = min(D[i][G[j][k]], D[i][j] + 1);
            }
        }
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(D[i][j] != n) ex[i] = max(ex[i], D[i][j]);
    return ex;
}
int rad(const vector< vector<int> > &G)
{
    vector<int> ex = excentres(G);
    int min_ex = ex.size();
    for(int i = 0; i < G.size(); i++) if(G[i].size()) min_ex = min(min_ex, ex[i]);
    return min_ex;
}
int diam(const vector< vector<int> > &G)
{
    vector<int> ex = excentres(G);
    int max_ex = 0;
    for(int i = 0; i < ex.size(); i++) if(G[i].size()) max_ex = max(max_ex, ex[i]);
    return max_ex;
}
void print_all_centers(const vector< vector<int> > &G, const vector<string> &Name)
{
    vector<int> ex = excentres(G);
    int min_ex = ex.size();
    for(int i = 0; i < G.size(); i++) if(G[i].size()) min_ex = min(min_ex, ex[i]);
    cout << "all centers are: "; for(int i = 0; i < G.size(); i++) if(ex[i] == min_ex) cout << Name[i] << "     ";
    cout << endl;
}
vector< vector<int> > graph_complement(vector< vector<int> >& G)
{
    int n = G.size();
    int A[n][n];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) A[i][j] = 1;
    for(int i = 0; i < n; i++) for(int j = 0; j < G[i].size(); j++) A[i][G[i][j]] = 0;
    for(int i = 0; i < n; i++) if(G[i].empty())
    {
        for(int j = 0; j < n; j++)
        {
            A[i][j] = 0;
            A[j][i] = 0;
        }
    }
    vector< vector<int> > G_complement(n);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(A[i][j] && i != j) G_complement[i].pb(j);
    return G_complement;
}
bool is_someone_full_incident(vector<int>& Not, vector<int>& candidates, vector< vector<int> >& G)
{
    for(int z = 0; z < Not.size(); z++) for(int i = 0; i < G[Not[z]].size(); i++)
    {
        int t = 1;
        for(int j = 0; j < candidates.size(); j++) if(G[Not[z]][i] != candidates[j]) t = 0;
        if(t) return true;
    }
    return false;
}
bool cmpsize(vector<int> A, vector<int> B)
{
    return A.size() < B.size();
}
void extend(vector<int>& compsub, vector<int>& candidates, vector<int>& Not, vector< vector<int> >& G, vector< vector<int> >& cliques)
{
    while(!candidates.empty() && !is_someone_full_incident(Not, candidates, G))
    {
        int v = candidates[0];
        compsub.push_back(v);
        vector<int> new_candidates, new_not;
        for(int i = 0; i < candidates.size(); i++)
        {
            int t = 0;
            for(int j = 0; j < G[v].size(); j++) if(G[v][j] == candidates[i]) t = 1;
            if(t) new_candidates.pb(candidates[i]);
        }
        for(int i = 0; i < Not.size(); i++)
        {
            int t = 0;
            for(int j = 0; j < G[v].size(); j++) if(G[v][j] == Not[i]) t = 1;
            if(t) new_not.pb(Not[i]);
        }
        if(new_candidates.empty() && new_not.empty())
        {
            cliques.pb(compsub);
            if(cliques.size() > 1000)
            {
                sort(cliques.begin(), cliques.end(), cmpsize);
                for(int i = 0; i < 500; i++) cliques.pop_back();
            }
        }
        else extend(compsub, new_candidates, new_not, G, cliques);
        for(int i = 0; i < compsub.size() - 1; i++) if(compsub[i] == v || i && compsub[i] == compsub[i-1]) compsub[i] = compsub[i+1];
        for(int i = 0; i < candidates.size() - 1; i++) if(candidates[i] == v || i && candidates[i] == candidates[i-1]) candidates[i] = candidates[i+1];
        compsub.pop_back();
        candidates.pop_back();
        Not.pb(v);
    }
}
vector< vector<int> > Brona_Kherboshi(vector< vector<int> >& G)
{
    vector< vector<int> > cliques;
    vector<int> compsub, candidates, Not;
    for(int i = 0; i < G.size(); i++) candidates.pb(i);
    extend(compsub, candidates, Not, G, cliques);
    return cliques;
}
vector<int> find_maximal_stable_set(vector< vector<int> > G)
{
    G = graph_complement(G);
    vector< vector<int> > stable_sets = Brona_Kherboshi(G);
    vector<int> cur_maximal_stable_set;
    for(int i = 0; i < stable_sets.size(); i++)
    {
        if(stable_sets[i].size() > cur_maximal_stable_set.size()) cur_maximal_stable_set = stable_sets[i];
    }
    return cur_maximal_stable_set;
}
signed main()
{
    int n, m;
    cin >> n >> m;
    string nm;
    getline(cin, nm);
    vector< vector<int> > G(n);
    vector<string> Name;
    for(int i = 0; i < n; i++)
    {
        string name;
        getline(cin, name);
        Name.pb(name);
    }
    cout << -1 << endl;
    for(int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }
    vector< vector<int> > Gcomp = max_component(G);
    print_min_degree(Gcomp, Name);
    print_max_degree(Gcomp, Name);
    cout << "radius is a " << rad(Gcomp) << endl;
    cout << "diameter is a " << diam(Gcomp) << endl;
    print_all_centers(Gcomp, Name);
    cout << "the maximal cliques of this graph is:" << endl;
    vector< vector<int> > cliques = Brona_Kherboshi(Gcomp);
    size_t ma = 0;
    for(int i = 0; i < cliques.size(); i++) ma = max(ma, cliques[i].size());
    int num = 1;
    for(int i = 0; i < cliques.size(); i++) if(ma == cliques[i].size())
    {
        cout << num << ": ";
        for(int j = 0; j < cliques[i].size(); j++) cout << Name[cliques[i][j]] << " | ";
        cout << endl;
        num++;
    }
    Ma = 0;
    cout << "the maximal stable set:" << endl;
    vector<int> stable_set = find_maximal_stable_set(Gcomp);
    for(int i = 0; i < stable_set.size(); i++) cout << stable_set[i] << " ";
    cout << endl;
}
/*
47 89
Albania
Andorra
Austria
Belarus
Belgium
Bosnia and Herzegovina
Bulgaria
Croatia
Cyprus
Czech Republic
Denmark
Estonia
Finland
France
Germany
Greece
Hungary
Iceland
Ireland
Italy
Kosovo
Latvia
Liechtenstein
Lithuania
Luxembourg
North Macedonia
Malta
Moldova
Monaco
Montenegro
Netherlands
Norway
Poland
Portugal
Romania
Russia
San Marino
Serbia
Slovakia
Slovenia
Spain
Sweden
Switzerland
Turkey
Ukraine
United
Vatican City
0 15
0 20
0 25
0 29
1 13
1 40
2 9
2 14
2 16
2 19
2 22
2 38
2 39
2 42
3 21
3 23
3 32
3 35
3 44
4 13
4 14
4 24
4 30
5 7
5 29
5 37
6 15
6 25
6 34
6 37
6 43
7 16
7 29
7 37
7 39
8 45
9 14
9 32
9 38
10 14
11 21
11 35
12 31
12 35
12 41
13 14
13 19
13 24
13 28
13 40
13 42
14 24
14 30
14 32
14 42
15 25
15 43
16 34
16 37
16 38
16 39
16 44
18 45
19 36
19 39
19 42
19 46
20 25
20 29
20 37
21 23
21 35
22 42
23 32
23 35
25 37
27 34
27 44
29 37
31 35
31 41
32 35
32 38
32 44
33 40
34 37
34 44
35 44
38 44
*/
