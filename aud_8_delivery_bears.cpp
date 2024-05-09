#include <bits/stdc++.h>
using namespace std;



struct edge {
    long long from, to, cap, originalCap;
};
vector<edge> edges;
vector<vector<int> > ng;
vector<int> parent;

bool bfs(int s, int t);
int fordFulkerson(int s, int t);
int n,m,x;

void add_edge(int from, int to, long long cap){
    edges.push_back({from,to,0,cap});
    edges.push_back({to,from,0,0});
    ng[from].push_back(edges.size()-2);
    ng[to].push_back(edges.size()-1);
}

void set_capacities(long double treshold){
    for(int i = 0 ; i < edges.size() ; i ++){
        edges[i].cap = edges[i].originalCap / treshold;
    }
}


int main(){
    cin>>n>>m>>x;
    ng.resize(n+m);
    parent.resize(ng.size());
    for(int i = 0 ; i < m ; i ++){
        int a,b,c;
        cin>>a>>b>>c;
        a --; b --;
        add_edge(a,b,c);
    }

    int source = 0;
    int target = n-1;

    long double l = 0, r = 1e9;
    while(l + 1e-12 < r){
        long double mid = (l+r)/2;
        set_capacities(mid);
        if(fordFulkerson(source,target) >= x){
            l = mid;
        } else {
            r = mid;
        }
    }
    cout<<fixed<<setprecision(10)<<l*x<<endl;
}




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
        long long pathFlow = LONG_LONG_MAX;
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
