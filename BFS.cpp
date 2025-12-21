#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsOfGraph(int V, vector<vector<int>> &adj, int start) {
    vector<int> bfs;              
    vector<int> vis(V+1, 0);       

    queue<int> q;
    q.push(start);               
    vis[start] = 1;

    while (!q.empty()) 
    {
        int node = q.front();
        q.pop();

        bfs.push_back(node);       

        for (auto it : adj[node]) 
        {
            if (!vis[it]) 
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V+1);

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

    vector<int> result = bfsOfGraph(V, adj, start);

    cout << "BFS Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
