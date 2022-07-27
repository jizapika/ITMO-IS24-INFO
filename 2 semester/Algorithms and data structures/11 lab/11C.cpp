

#include<bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("pathbgep.in", "r", stdin);
    freopen("pathbgep.out", "w", stdout);
  int n,s,m,a,b,c;
  cin>>n>>m;
  s = 0;
  vector<vector<pair<int,int> > >G(n);
  vector<int>D(n,2009000999);D[s]=0;
  vector<int>P(n,-1);
  for(int i=0; i<m; i++)
  {
    cin>>a>>b>>c;
    G[a-1].push_back({b-1,c});
    G[b-1].push_back({a-1,c});
  }
  set<pair<int,int> >q;
  q.insert({0,s});
  while(!q.empty())
  {
    set<pair<int,int> >::iterator it=q.begin();
    pair<int,int>r=*it;
    int u=r.second;
    q.erase(it);
    for(int i=0; i<G[u].size(); i++)
    {
        int to=G[u][i].first;
        int len=G[u][i].second;
        it=q.find({D[to],to});
        if(it!=q.end()&&D[to]>D[u]+len)q.erase(it);
        if(D[to]>D[u]+len)
        {
            D[to]=D[u]+len;
            q.insert({D[to],to});
        }
    }
  }
  for(int i=0; i<n; i++)cout<<D[i]<<" ";
}
