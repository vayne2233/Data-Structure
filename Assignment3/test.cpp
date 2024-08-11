#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<vector<int>> subtree_weights;
vector<int> weights;
vector<int> result;
int N, Q;

void dfs(int node, int parent)
{
    subtree_weights[node].push_back(weights[node]);
    for (int child : tree[node])
    {
        if (child != parent)
        {
            dfs(child, node);
            subtree_weights[node].insert(subtree_weights[node].end(), subtree_weights[child].begin(), subtree_weights[child].end());
        }
    }
    sort(subtree_weights[node].begin(), subtree_weights[node].end(), greater<int>());
    if (subtree_weights[node].size() > 20)
    {
        subtree_weights[node].resize(20); // Trim to at most 20 largest elements
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> Q;
    tree.resize(N + 1);
    subtree_weights.resize(N + 1);
    weights.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < N - 1; i++)
    {
        int A, B;
        cin >> A >> B;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }

    dfs(1, 0);

    for (int i = 0; i < Q; i++)
    {
        int V, K;
        cin >> V >> K;
        cout << subtree_weights[V][K - 1] << '\n';
    }

    return 0;
}