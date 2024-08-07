#include <iostream>
#include <vector>
#include <functional>
using namespace std;

vector<int> pre(2000005), in(2000005), pos(2000005);

struct node
{
    int val;
    node *l = NULL;
    node *r = NULL;
    node(int x, node *l = NULL, node *r = NULL) : val(x) {}
};

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> pre[i];
    for (int i = 0; i < n; ++i)
    {
        cin >> in[i];
        pos[in[i]] = i;
    }

    function<node *(int, int)> build = [&](int l, int r)
    {
        if (l > r)
            return (node *)(NULL);
        static int now = 0;
        node *res = new node(pre[now++]);
        res->l = build(l, pos[res->val] - 1);
        res->r = build(pos[res->val] + 1, r);
        return res;
    };

    function<void(node *)> postorder = [&](node *t)
    {
        if (!t)
            return;
        postorder(t->l);
        postorder(t->r);
        cout << t->val << ' ';
        return;
    };

    node *t = build(0, n - 1);
    postorder(t);
}