
#include<iostream>
using namespace std;
struct train
{
    train *q;
    int a;
};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    train stackback;
    char a;
    while(cin>>a)
    {
        if(a >= '0' && a <= '9')
        {
            int k = a - '0';
            train *g = new train (stackback);
            stackback = {g , k};
        }
        else
        {
            int s = stackback.a;
            stackback = *stackback.q;
            int f = stackback.a;
            stackback = *stackback.q;
            int k;
            if(a == '+') k = f + s;
            if(a == '-') k = f - s;
            if(a == '*') k = f * s;
            train *g = new train (stackback);
            stackback = {g , k};
        }
    }
    cout<<stackback.a<<endl;
}
