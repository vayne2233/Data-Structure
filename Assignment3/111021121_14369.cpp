#include <iostream>
#include <vector>
#include <functional>
using namespace std;

struct node
{
    int val;
    node *l = NULL;
    node *r = NULL;
    node(int x, node *l = NULL, node *r = NULL) : val(x) {}
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n, now;
        now = 0;
        cin >> n;
        vector<int> pre(n), in(n), pos(n + 5), post(n), ans;
        ans.resize(0);
        for (int i = 0; i < n; ++i)
            cin >> pre[i];
        for (int i = 0; i < n; ++i)
        {
            cin >> in[i];
            pos[in[i]] = i;
        }
        for (int i = 0; i < n; ++i)
            cin >> post[i];

        function<node *(int, int)> build = [&](int l, int r)
        {
            if (l > r)
                return (node *)(NULL);
            else if (now > n - 1)
                return (node *)(NULL);
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
            ans.emplace_back(t->val);
        };

        node *x = build(0, n - 1);
        postorder(x);
        cout << (ans == post ? "yes\n" : "no\n");
    }
}