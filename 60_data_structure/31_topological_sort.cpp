#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& stk) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, stk);
        }
    }
    stk.push(node);
}

vector<int> topologicalSort(int n, vector<vector<int>>& graph) {
    vector<bool> visited(n, false);
    stack<int> stk;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, stk);
        }
    }

    vector<int> result;
    while (!stk.empty()) {
        result.push_back(stk.top());
        stk.pop();
    }

    return result;
}

int main() {
    int n = 6;
    vector<vector<int>> graph(n);

    /*
        src ==> dest
         2  ==>  3
         3  ==>  1
         4  ==>  0
         4  ==>  1
         5  ==>  0
         5  ==>  2

        node    start   finish
        0       1       2
        1       2       3
        2       4       7
        3       5       6
        4       8       9
        5       10      11
    */
    graph[2].push_back(3);
    graph[3].push_back(1);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[5].push_back(0);
    graph[5].push_back(2);

    vector<int> sorted = topologicalSort(n, graph);
    for (int node : sorted) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
