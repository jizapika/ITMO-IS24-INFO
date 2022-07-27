#include<iostream>
using namespace std;
int Qsort(int A[], int l, int r, int k)
{
int key = A[k];
int l1=l,r1=r;
while(l1<r1)
{
while (A[l1]<key)l1++;
while (A[r1]>key)r1--;
if(l1<r1)swap(A[l1],A[r1]);
if(A[l1]==key&&A[r1]==key&&r1!=l1)
{
if(k-l1>r1-k)l1++;
else r1--;
}
}
if(l1==k)return key;
if(l1<k)return Qsort(&A[0],l1+1,r,k);
if(l1>k)return Qsort(&A[0],l,l1-1,k);
}
int main()
{
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//freopen("kth.in", "r", stdin);
//freopen("kth.out", "w", stdout);
int n, k;
cin>>n>>k;
int a,b,c,a1,a2;
cin>>a>>b>>c>>a1>>a2;
int A[n];
if(n>=1)A[0]=a1;
if(n>=2)A[1]=a2;
for(int i=2; i<n; i++)A[i]=a*A[i-2]+b*A[i-1]+c;
if(k==1)
{
	int mi=A[0];
	for(int i=0; i<n; i++)mi=min(mi,A[i]);
	cout<<mi;
	return 0;
}
if(k==n)
{
	int ma=A[0];
	for(int i=0; i<n; i++)ma=max(ma,A[i]);
	cout<<ma;
	return 0;
}
cout << Qsort(&A[0], 0, n-1, k-1);
}
