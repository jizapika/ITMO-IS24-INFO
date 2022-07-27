#include <iostream>
#define ll long long
#define int long long
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

signed main ()
{
  freopen("sortland.in", "r", stdin);
  freopen("sortland.out", "w", stdout);
  int n;
  cin>>n;
  pair<float,int> A[n];
  for(int i=0; i<n; i++)
  {
      float a;
      cin>>a;
      A[i]={a,i+1};
  }
  for(int i=0; i<n; i++)
  {
      int j=i;
      while(j>0&&A[j].f<A[j-1].f)
      {
          swap(A[j-1],A[j]);
          j--;
      }
  }
  cout<<A[0].s<<" "<<A[n/2].s<<" "<<A[n-1].s;
}
