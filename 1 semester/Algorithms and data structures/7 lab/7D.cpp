#include<iostream>
#include<vector>
#define int long long
#define f first
#define s second
#define pb push_back
using namespace std;
struct node
{
    int value, left, right, parent;
};
vector<node> tree;
int head = -1;
vector<int> H;
vector<int> B;
void dfsB(int id)
{
    int Hl = 0, Hr = 0;
    if(tree[id].left != -1)
    {
        dfsB(tree[id].left);
        H[id] = max(H[id], H[tree[id].left] + 1);
        Hl = H[tree[id].left];
    }
    if(tree[id].right != -1)
    {
        dfsB(tree[id].right);
        H[id] = max(H[id], H[tree[id].right] + 1);
        Hr = H[tree[id].right];
    }
    B[id] = Hr - Hl;
}
void Bcount()
{
    if(tree.empty())return;
    B.resize(tree.size());
    H.resize(tree.size(), 1);
    dfsB(head);
}
void scantree(int n)
{
    if(n == 0)return;
    head = 0;
    tree.resize(n);
    tree[0].parent = -1;
    for(int i = 0; i < n; i++)
    {
        cin >> tree[i].value >> tree[i].left >> tree[i].right;
        tree[i].left--;
        tree[i].right--;
        if(tree[i].left != -1) tree[tree[i].left].parent = i;
        if(tree[i].right != -1) tree[tree[i].right].parent = i;
    }
    Bcount();
}
void printtree()
{
    cout << tree.size() << endl;
    for(int i = 0; i < tree.size(); i++) cout << tree[i].value << " " << tree[i].left + 1 << " " << tree[i].right + 1 << '\n';
}

int pos;
vector<node> newtree;
void dfs(int a)
{
    int u = pos;
    newtree[u].value = tree[a].value;
    if(tree[a].left != -1)
    {
        pos++;
        newtree[u].left = pos;
        newtree[pos].parent = u;
        dfs(tree[a].left);
    }
    else
    {
        newtree[u].left = -1;
    }
    if(tree[a].right != -1)
    {
        pos++;
        newtree[u].right = pos;
        newtree[pos].parent = u;
        dfs(tree[a].right);
    }
    else
    {
        newtree[u].right = -1;
    }
}
void treeclear()
{
    vector<node> K;
    for(int i = 0; i < tree.size(); i++) if(i == head || tree[i].parent != -1) K.pb(tree[i]);
    tree = K;
}
void sorttree()
{
    if(tree.size()) newtree.resize(tree.size());
    else return;
    pos = 0;
    for(int i = 0; i < tree.size(); i++) newtree[i].parent = -1;
    dfs(head);
    head = 0;
    tree = newtree;
    treeclear();
    newtree.clear();
    head = 0;
    B.resize(tree.size());
    Bcount();
}
void rotateleft(int id)
{
    int p = tree[id].parent;
    int h1L = 0, h2L = 0, h1R = 0, h2R = 0;
    if(tree[id].left != -1) h1L = H[tree[id].left];
    if(tree[tree[id].right].left != -1) h1R = H[tree[tree[id].right].left];
    H[id] = max(h1L, h1R) + 1;
    B[id] = h1R - h1L;
    if(tree[tree[id].right].right != -1) h2R = H[tree[tree[id].right].right];
    h2L = H[id];
    H[tree[id].right] = max(h2L, h2R) + 1;
    B[tree[id].right] = h2R - h2L;
    int a = 0;
    if(p != -1 && tree[tree[id].parent].left == id) a = -1;
    if(p != -1 && tree[tree[id].parent].right == id) a = 1;
    int id2 = tree[id].right;
    if(tree[tree[id].right].left != -1) tree[tree[tree[id].right].left].parent = id;
    tree[id].right = tree[tree[id].right].left;
    tree[id2].left = id;
    tree[id].parent = id2;
    tree[id2].parent = p;
    if(a == -1) tree[p].left = id2;
    if(a == 1) tree[p].right = id2;
    if(head == id) head = id2;
}
void rotateright(int id)
{
    int p = tree[id].parent;
    int h1L = 0, h2L = 0, h1R = 0, h2R = 0;
    if(tree[id].right != -1) h1R = H[tree[id].right];
    if(tree[tree[id].left].right != -1) h1L = H[tree[tree[id].left].right];
    H[id] = max(h1L, h1R) + 1;
    B[id] = h1R - h1L;
    if(tree[tree[id].left].left != -1) h2L = H[tree[tree[id].left].left];
    h2R = H[id];
    H[tree[id].left] = max(h2L, h2R) + 1;
    B[tree[id].left] = h2R - h2L;
    int a = 0;
    if(p != -1 && tree[tree[id].parent].left == id) a = -1;
    if(p != -1 && tree[tree[id].parent].right == id) a = 1;
    int id2 = tree[id].left;
    if(tree[tree[id].left].right != -1) tree[tree[tree[id].left].right].parent = id;
    tree[id].left = tree[tree[id].left].right;
    tree[id2].right = id;
    tree[id].parent = id2;
    tree[id2].parent = p;
    if(a == -1) tree[p].left = id2;
    if(a == 1) tree[p].right = id2;
    if(head == id) head = id2;
}
void bigrotateleft(int id)
{
    rotateright(tree[id].right);
    rotateleft(id);
}
void bigrotateright(int id)
{
    rotateleft(tree[id].left);
    rotateright(id);
}
void balance(int id)
{
    if(B[id] == 2 && B[tree[id].right] != -1)
    {
        rotateleft(id);
    }
    else if(B[id] == 2 && B[tree[id].right] == -1)
    {
        bigrotateleft(id);
    }

    if(B[id] == -2 && B[tree[id].left] != 1)
    {
        rotateright(id);
    }
    else if(B[id] == -2 && B[tree[id].left] == 1)
    {
        bigrotateright(id);
    }
}
int findernear(int a)
{
    int cur = head;
    while(tree[cur].left != -1 || tree[cur].right != -1 || tree[cur].value != a)
    {
        if(tree[cur].left != -1 && a < tree[cur].value) cur = tree[cur].left;
        else if(tree[cur].right != -1 && a > tree[cur].value) cur = tree[cur].right;
        else break;
    }
    return cur;
}
void pushkey(int a)
{
    int pos = -1;
    node K;
    K.parent = pos;
    K.left = -1;
    K.right = -1;
    K.value = a;
    if(tree.empty())
    {
        tree.pb(K);
        head = 0;
        B.pb(0);
        H.pb(1);
        return;
    }
    pos = findernear(a);
    K.parent = pos;
    if(tree[pos].value > a)
    {
        tree.pb(K);
        tree[pos].left = tree.size() - 1;
        H.pb(1);
        B.pb(0);
    }
    if(tree[pos].value < a)
    {
        tree.pb(K);
        tree[pos].right = tree.size() - 1;
        H.pb(1);
        B.pb(0);
    }
    if(tree[pos].value == a)
    {
        return;
    }
    while(pos != -1)
    {
        int parent = tree[pos].parent;
        int Hl = 0, Hr = 0;
        if(tree[pos].left != -1) Hl = H[tree[pos].left];
        if(tree[pos].right != -1) Hr = H[tree[pos].right];
        H[pos] = max(Hl, Hr) + 1;
        B[pos] = Hr - Hl;
        balance(pos);
        pos = parent;
    }
}
void erasekey(int a)
{
    if(head == -1 || tree[head].left == -1 && tree[head].right == -1)
    {
        if(head == -1 || tree[head].value == a)
        {
            tree.clear();
            head = -1;
        }
        return;
    }
    int pos = findernear(a);
    if(tree[pos].value != a) return;
    int p;
    if(tree[pos].left == -1)
    {
        if(tree[pos].right == -1) p = tree[pos].parent;
        else
        {
            p = pos;
            pos = tree[pos].right;
            swap(tree[p].value, tree[pos].value);
        }
        tree[pos].parent = -1;
        if(tree[p].left == pos) tree[p].left = -1;
        if(tree[p].right == pos) tree[p].right = -1;
    }
    else
    {
        int pos2 = tree[pos].left;
        while(tree[pos2].right != -1)
        {
            pos2 = tree[pos2].right;
        }
        swap(tree[pos].value, tree[pos2].value);
        if(tree[pos2].left != -1)
        {
            swap(tree[pos2].value, tree[tree[pos2].left].value);
            pos2 = tree[pos2].left;
        }
        p = tree[pos2].parent;
        tree[pos2].parent = -1;
        if(tree[p].right == pos2) tree[p].right = -1;
        if(tree[p].left == pos2) tree[p].left = -1;
    }
    while(p != -1)
    {
        int Hl = 0, Hr = 0;
        if(tree[p].right != -1) Hr = H[tree[p].right];
        if(tree[p].left != -1) Hl = H[tree[p].left];
        H[p] = max(Hl, Hr) + 1;
        B[p] = Hr - Hl;
        balance(p);
        p = tree[p].parent;
    }
}
int finder(int x)
{
    if(head == -1) return 0;
    int pos = findernear(x);
    if(tree[pos].value == x) return 1;
    return 0;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("deletion.in", "r", stdin);
    freopen("deletion.out", "w", stdout);
    int n;
    cin >> n;
    scantree(n);
    int x;
    cin >> x;
    erasekey(x);
    sorttree();
    printtree();
}
