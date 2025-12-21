#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &res) {
    vis[node] = 1;
    res.push_back(node);

    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis, res);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<vector<int>> &adj, int start) {
    vector<int> vis(V + 1, 0);  
    vector<int> res;

    dfs(start, adj, vis, res);
    return res;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V + 1); 

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    vector<int> dfsTraversal = dfsOfGraph(V, adj, start);

    cout << "DFS Traversal: ";
    for (int node : dfsTraversal) {
        cout << node << " ";
    }

    return 0;
}
