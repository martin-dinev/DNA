#include<bits/stdc++.h>

using namespace std;

int n, m;
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

int max_matching() {
    n += 2;
    ng.resize(n);
    parent.resize(n);
    set<int> left, right;
    for (int i = 0; i < edges.size(); i += 2) {
        left.insert(edges[i].from);
        right.insert(edges[i].to);
    }
    for (auto &i : left) {
        edges.push_back({n-2, i, 1});
        ng[n-2].push_back(edges.size() - 1);
        edges.push_back({i, n-2, 0});
        ng[i].push_back(edges.size() - 1);
    }
    for (auto &i : right) {
        edges.push_back({i, n - 1, 1});
        ng[i].push_back(edges.size() - 1);
        edges.push_back({n - 1, i, 0});
        ng[n - 1].push_back(edges.size() - 1);
    }
    return fordFulkerson(n-2, n-1);
}

// eg. input bipartite matching
/* // node with index 0 is unused
7 6
1 4
2 5
3 6
1 5
2 6
3 4
*/

int main() {
    cin >> n >> m;
    ng.resize(n);
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        edges.push_back({a, b, 1});
        ng[a].push_back(edges.size() - 1);
        edges.push_back({b, a, 0});
        ng[b].push_back(edges.size() - 1);
    }

    parent.resize(n);
    cout << max_matching() << endl;
    for(int i = 0 ; i < m*2 ; i += 2){
        if(edges[i].cap == 0){
            cout<<edges[i].from<<" "<<edges[i].to<<endl;
        }
    }

}

