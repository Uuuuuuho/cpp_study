#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &adj, int start) {
    queue<int> q;
    vector<bool> visited(adj.size(), false);
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    // Read graph input
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Perform BFS starting from node 0
    bfs(adj, 0);

    return 0;
}

/*

Example input
6 7
0 1
0 2
1 2
1 3
2 4
3 4
4 5

Example output
0 1 2 3 4 5

*/