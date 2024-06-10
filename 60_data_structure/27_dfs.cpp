#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph) {
    // Mark the current node as visited
    visited[node] = true;
    cout << node << " ";

    // Recur for all adjacent nodes that are not visited
    for (int i = 0; i < graph[node].size(); i++) {
        int adj = graph[node][i];
        if (!visited[adj]) {
            dfs(adj, visited, graph);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize the graph with n nodes
    vector<vector<int>> graph(n);

    // Read the edges and add them to the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Initialize the visited array
    vector<bool> visited(n, false);

    // Perform DFS on all unvisited nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, visited, graph);
        }
    }

    return 0;
}

/*

Example input
6 8
0 1
0 2
1 3
1 4
2 4
3 4
3 5
4 5

Example output
0 1 3 4 2 5

*/