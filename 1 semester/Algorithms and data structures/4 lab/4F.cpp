#include<iomanip>
#include<iostream>
using namespace std;
int main()
{
    freopen("garland.in", "r", stdin);
    freopen("garland.out", "w", stdout);
    int n;
    cin >> n;
    long double A;
    cin >> A;
    long double res;
    long double l = 0, r = A;
    while(r - l > 1e-5)
    {
        long double m = (l + r) / 2;
        res = m;
        long double prev = A;
        int s=0;
        for(int i=2; i<n; i++)
        {
            long double k = prev;
            prev = res;
            res = (res + 1) * 2 - k;
            if(res < 1e-5) s++;
        }
        if(s) l = m;
        else r = m;
    }
    cout<<fixed<<setprecision(9)<<res<<endl;
}
