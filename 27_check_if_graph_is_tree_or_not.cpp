#include <bits/stdc++.h>
using namespace std;

#define MAX
vector<int> g[MAX];
int vis[MAX] = {0};

bool isCycle(int u, int parent)
{
    vis[u] = true;
    for (auto v : g[u])
    {
        if (!vis[v] && isCycle(v, u))
            return true;
        if (v != parent)
            return true;
    }
    return false;
}

void markConnected(int u)
{
    vis[u] = true;
    for (auto v : g[u])
        if (!vis[v])
            markConnected(v);
}

bool checkTree(int edges)
{
    if (isCycle(0, -1))
        return false;
    markConnected(0);
    for (int i = 0; i < edges; i++)
        if (!vis[i])
            return false;
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    cout << (checkTree(m) ? "It's a tree" : "It's not a tree, it's a graph") << endl;
    return 0;
}
