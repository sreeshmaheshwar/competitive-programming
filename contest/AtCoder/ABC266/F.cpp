/* 
Explanation:

Since a tree consists of N nodes and (N - 1) edges, we can 
think of a connected, undirected graph with N nodes and 
N edges, such as the one we are provided with, as simply a tree 
with an added edge. This added edge will cause a violation of the 
acyclic property of trees, and will more specifically create 
exactly one cycle - to understand why this is the case, picture
an arbitrary tree (rooted to help with visualisation), and add
an arbitrary edge to it. It should then be clear that this
creates precisely one cycle (of length greater than 2, naturally).

Furthermore, the nodes of this cycle can be thought of as roots
of subtrees, with these subtrees partitioning the original graph 
itself. Furthermore, if two nodes are in the same subtree,
there will be a unique path between them (this is a well-known property
of all trees), whereas if they are not, then we may travel
from node X to node Y as follows: X -> subtree_root(X) -> subtree_root(Y) -> Y.
However, since subtree_root(X) and subtree_root(Y) are distinct nodes of a cycle, 
there are multiple ways of travelling between them (namely, we can
go both "clockwise" and "anti-clockwise" around the cycle from subtree_root(X)
to subtree_root(Y), for whatever direction we choose to define as clcokwise).
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dfs_parent;
vector<int> cycle_nodes;
vector<int> subtree_root;
vector<bool> is_cycle;

void cycle_dfs(int node) {
    for (int neighbour : adj[node]) {
        if (neighbour == dfs_parent[node]) continue;
        if (dfs_parent[neighbour] == -1) {
            dfs_parent[neighbour] = node;
            cycle_dfs(neighbour);
        } else if (cycle_nodes.empty()) {
            int cycle_node = node;
            while (cycle_nodes.empty() || cycle_node != dfs_parent[neighbour]) {
                cycle_nodes.push_back(cycle_node);
                is_cycle[cycle_node] = true;
                cycle_node = dfs_parent[cycle_node];
            }
        }
    }
}

void subtree_dfs(int node, int parent) {
    for (int child : adj[node]) {
        if (child == parent || is_cycle[child]) continue;
        subtree_root[child] = subtree_root[node];
        subtree_dfs(child, node);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    adj = vector<vector<int>>(n);
    dfs_parent = vector<int>(n, -1);
    subtree_root = vector<int>(n);
    cycle_nodes = vector<int>();
    is_cycle = vector<bool>(n, false);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cycle_dfs(0);
    for (int node : cycle_nodes) {
        subtree_root[node] = node;
        subtree_dfs(node, -1);
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << (subtree_root[a] == subtree_root[b] ? "Yes" : "No") << '\n';
    }
    return 0;
}