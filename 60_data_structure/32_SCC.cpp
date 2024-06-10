#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void dfs(int u, vector<vector<int>>& graph, vector<int>& ids, vector<int>& low, vector<int>& on_stack, stack<int>& s, int& id, vector<vector<int>>& scc) {
    ids[u] = low[u] = ++id;
    on_stack[u] = true;
    s.push(u);
    
    for (int v : graph[u]) {
        if (ids[v] == 0) {
            dfs(v, graph, ids, low, on_stack, s, id, scc);
            low[u] = min(low[u], low[v]);
        } else if (on_stack[v]) {
            low[u] = min(low[u], ids[v]);
        }
    }
    
    if (ids[u] == low[u]) {
        scc.push_back({});
        while (true) {
            int v = s.top();
            s.pop();
            on_stack[v] = false;
            scc.back().push_back(v);
            if (v == u) {
                break;
            }
        }
    }
}

vector<vector<int>> find_scc(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> ids(n), low(n), on_stack(n);
    stack<int> s;
    int id = 0;
    vector<vector<int>> scc;
    
    for (int i = 0; i < n; i++) {
        if (ids[i] == 0) {
            dfs(i, graph, ids, low, on_stack, s, id, scc);
        }
    }
    
    return scc;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    
    vector<vector<int>> scc = find_scc(graph);
    
    for (auto component : scc) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/* 
    Example input
    5 5
    0 1
    1 2
    2 0
    2 3
    3 4
*/

/* There is python code in algorithm directory, "2150_SCC.py" as well. */
/* This is Tarjan's SCC algorithm. */
/* Refer this link, https://taesung1993.tistory.com/53. */