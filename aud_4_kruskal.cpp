#include<bits/stdc++.h>

using namespace std;
#define MAX_N 10000

struct edge {
    int cost;
    int a, b;

    bool operator<(const edge &other) const {
        return cost < other.cost;
    }
};

struct DSU {
    vector<int> parent;
    vector<int> set_size;

    DSU(int n) {
        parent.resize(n);
        set_size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            set_size[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        // return find(parent[x]); // ova kje raboti
        // no postoi optimizacija - path compression
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (set_size[x] < set_size[y]) swap(x, y);
        parent[y] = x;
        set_size[x] += set_size[y];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

vector<pair<int, int> > edges[MAX_N];
int n, m;

vector<edge> kruskal() {
    vector<edge> all_edges;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < edges[i].size(); j++)
            all_edges.push_back({edges[i][j].second, i, edges[i][j].first});

    sort(all_edges.begin(), all_edges.end());
    DSU dsu(n);
    vector<edge> rez;
    for (int i = 0; i < all_edges.size(); i++) {
        if (!dsu.same(all_edges[i].a, all_edges[i].b)) {
            dsu.unite(all_edges[i].a, all_edges[i].b);
            rez.push_back(all_edges[i]);
        }
    }
    return rez;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edges[a].push_back({b, cost});
        edges[b].push_back({a, cost});
    }
    vector<edge> mst = kruskal();
    for (int i = 0; i < mst.size(); i++) {
        cout << mst[i].a << " " << mst[i].b << " " << mst[i].cost << endl;
    }
}

/*
5 8
0 1 4
0 2 2
1 2 1
1 3 2
1 4 3
2 3 4
2 4 5
3 4 1
*/