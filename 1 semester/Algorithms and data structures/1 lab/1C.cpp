#include <iostream>

using namespace std;

int main ()
{
  long long a, b;
  freopen("turtle.in", "r", stdin);
  freopen("turtle.out", "w", stdout);
  cin >> a >> b;
  long long A[a][b],B[a][b];
  for(int i=0; i<a; i++)for(int j=0; j<b; j++)cin>>B[i][j];
  for(int i=a-1; i>=0; i--)for(int j=0; j<b; j++)
  {
      if(j>0&&i<a-1)A[i][j]=max(A[i+1][j],A[i][j-1])+B[i][j];
      if(j==0&&i<a-1)A[i][j]=A[i+1][j]+B[i][j];
      if(j>0&&i==a-1)A[i][j]=A[i][j-1]+B[i][j];
      if(j==0&&i==a-1)A[i][j]=B[i][j];
  }
  cout<<A[0][b-1];
  return 0;
}
