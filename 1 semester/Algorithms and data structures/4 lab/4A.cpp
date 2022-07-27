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
    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);
    int m;
    cin>>m;
    train stackback;
    char a;
    while(cin>>a)
    {
        if(a == '+')
        {
            int k;
            cin>>k;
            train *g = new train (stackback);
            stackback = {g , k};
        }
        else
        {
            cout<<stackback.a<<endl;
            stackback = *stackback.q;
        }
    }
}
