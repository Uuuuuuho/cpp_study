#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int color[MAXN];

bool dfs(int u, int c) {
    color[u] = c;
    for (int v : adj[u]) {
        if (color[v] == c) {
            return false;
        }
        if (color[v] == 0 && !dfs(v, -c)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool is_bipartite = true;
    for (int u = 1; u <= n; u++) {
        if (color[u] == 0 && !dfs(u, 1)) {
            is_bipartite = false;
            break;
        }
    }

    if (is_bipartite) {
        vector<int> A, B;
        for (int u = 1; u <= n; u++) {
            if (color[u] == 1) {
                A.push_back(u);
            } else {
                B.push_back(u);
            }
        }
        cout << "The graph is bipartite." << endl;
        cout << "Set A: ";
        for (int u : A) {
            cout << u << " ";
        }
        cout << endl;
        cout << "Set B: ";
        for (int u : B) {
            cout << u << " ";
        }
        cout << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}


/* 

Exmaple input
    5 5
    0 1
    0 3
    1 2
    2 3
    3 4

Example output
    The graph is bipartite.
    Set A: 1 3 5 
    Set B: 2 4 

*/