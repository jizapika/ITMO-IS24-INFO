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
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    train stackback;
    string S;
    while(cin>>S)
    {
        int t = 1;
        int sze = 0;
        for(int i=0; i<S.length(); i++)
        {
            if(S[i] == '(' || S[i] == '[')
            {
                int k;
                if(S[i] == '(')k = 1;
                else k = 2;
                train *g = new train (stackback);
                stackback = {g , k};
                sze++;
            }
            else
            {
                int k;
                if(S[i] == ')')k = 1;
                else k = 2;
                if(k == stackback.a)
                {
                    if(sze == 0)
                    {
                        t = 0;
                        cout<<"NO"<<endl;
                        break;
                    }
                    stackback = *stackback.q;
                    sze--;
                }
                else
                {
                    t = 0;
                    cout<<"NO"<<endl;
                    break;
                }
            }
        }
        if(sze == 0 && t)cout<<"YES"<<endl;
        else if(t)cout<<"NO"<<endl;
    }
}
