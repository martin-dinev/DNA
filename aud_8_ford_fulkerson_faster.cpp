#include<bits/stdc++.h>

using namespace std;

struct edge {
    int from, to, cap;
};
vector<edge> edges;
vector<vector<int> > ng;
vector<int> parent;

bool bfs(int s, int t) {
    fill(parent.begin(), parent.end(), -1);
    vector<bool> visited(ng.size(), false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < ng[u].size(); i++) {
            edge &e = edges[ng[u][i]];
            if (!visited[e.to] && e.cap > 0) {
                q.push(e.to);
                parent[e.to] = ng[u][i];
                visited[e.to] = true;
            }
        }
    }
    return visited[t];
}

int fordFulkerson(int s, int t) {
    int maxFlow = 0;
    while (bfs(s, t)) {
        int pathFlow = INT_MAX;
        for (int v = t; v != s; v = edges[parent[v]].from) {
            pathFlow = min(pathFlow, edges[parent[v]].cap);
        }
        for (int v = t; v != s; v = edges[parent[v]].from) {
            edges[parent[v]].cap -= pathFlow;
            edges[parent[v] ^ 1].cap += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}

// example input
/*
6 10
0 1 16
0 2 13
1 2 10
1 3 12
2 1 4
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4
 */

int main() {
    int n, m;
    cin >> n >> m;
    ng.resize(n);
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
        ng[a].push_back(edges.size() - 1);
        edges.push_back({b, a, 0});
        ng[b].push_back(edges.size() - 1);
    }

    parent.resize(n);
    cout << fordFulkerson(0, n - 1) << endl;
}

