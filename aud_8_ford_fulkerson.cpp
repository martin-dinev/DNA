#include<bits/stdc++.h>

using namespace std;

class FordFulkerson {
    vector<vector<int>> capacity;
    vector<vector<int>> flow;
    vector<int> parent;
    int n;

    bool bfs(int s, int t) {
        fill(parent.begin(), parent.end(), -1);
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; v++) {
                if (!visited[v] && capacity[u][v] - flow[u][v] > 0) {
                    q.push(v);
                    parent[v] = u;
                    visited[v] = true;
                }
            }
        }
        return visited[t];
    }

    int fordFulkerson(int s, int t) {
        int maxFlow = 0;
        while (bfs(s, t)) {
            int pathFlow = INT_MAX;
            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                pathFlow = min(pathFlow, capacity[u][v] - flow[u][v]);
            }
            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                flow[u][v] += pathFlow;
                flow[v][u] -= pathFlow;
            }
            maxFlow += pathFlow;
        }
        return maxFlow;
    }

public:
    FordFulkerson(vector<vector<int>> capacity) {
        this->capacity = capacity;
        n = capacity.size();
        flow = vector<vector<int>>(n, vector<int>(n, 0));
        parent = vector<int>(n, -1);
    }

    int maxFlow(int s, int t) {
        return fordFulkerson(s, t);
    }
};


int main() {
    vector<vector<int>> capacity = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };
    FordFulkerson ff(capacity);
    cout << ff.maxFlow(0, 5) << endl; // 23
    return 0;
}

