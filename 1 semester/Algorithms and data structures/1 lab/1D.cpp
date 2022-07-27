#include <iostream>
#define ll long long
#define int long long
using namespace std;

signed main ()
{
  freopen("smallsort.in", "r", stdin);
  freopen("smallsort.out", "w", stdout);
  int n;
  cin>>n;
  int A[n];
  for(int i=0; i<n; i++)cin>>A[i];
  for(int i=0; i<n; i++)
  {
      int j=i;
      while(j>0&&A[j]<A[j-1])
      {
          swap(A[j-1],A[j]);
          j--;
      }
  }

  for(int i=0; i<n; i++)cout<<A[i]<<" ";
}
