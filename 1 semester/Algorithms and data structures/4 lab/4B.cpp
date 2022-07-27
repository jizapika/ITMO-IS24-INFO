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
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
    int m;
    cin>>m;
    train queueback;
    char a;
    train *g;
    train *h;
    int sze = 0;
    int k;
    while(cin>>a)
    {
        if(a == '+')
        {
            cin>>k;
            queueback.a = k;
            h = g;
            g = new train (queueback);
            if(sze == 0)(*g).q = g;
            else
            {
                (*g).q = (*h).q;
                (*h).q = g;
            }
            sze++;
        }
        else
        {
            cout<<(*(*g).q).a<<endl;
            (*g).q = (*(*g).q).q;
            sze--;
        }
    }
}

