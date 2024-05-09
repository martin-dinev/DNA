#include <bits/stdc++.h>
using namespace std;
vector<int> a,b;
int n;

struct edge {
    int from, to, cap;
};
vector<edge> edges;
vector<vector<int> > ng;
vector<int> parent;

bool bfs(int s, int t);
int fordFulkerson(int s, int t);

map<long long, int> mp;
int get_ind(long long x){
    if(mp.find(x) == mp.end()){
        mp[x] = mp.size() + n;
    }
    return mp[x];
}

void add_edge(int from, int to){
    edges.push_back({from,to,1});
    edges.push_back({to,from,0});
    ng[from].push_back(edges.size()-2);
    ng[to].push_back(edges.size()-1);
}

int main(){
    cin>>n;
    ng.resize(4*n+2);
    a.resize(n);
    b.resize(n);
    for(int i = 0 ; i < n ; i ++){
        cin>>a[i]>>b[i];
        int x = get_ind(a[i]+b[i]);
        int y = get_ind(a[i]-b[i]);
        int z = get_ind(a[i]*b[i]);
        add_edge(i,x);
        add_edge(i,y);
        add_edge(i,z);
    }

    int source = n + mp.size();
    int sink = source + 1;

    for(int i = 0 ; i < n ; i ++)
        add_edge(source,i);
    for(int i = n ; i < source ; i ++)
        add_edge(i,sink);

    parent.resize(ng.size());
    int rez = fordFulkerson(source,sink);
    if(rez != n){
        cout<<"impossible\n";
        return 0;
    }

    for(int i = 0 ; i < n ; i ++){
        if(edges[ng[i][0]].cap == 0)
            cout<<a[i]<<" + "<<b[i]<<" = "<<a[i]+b[i]<<endl;
        else if(edges[ng[i][1]].cap == 0)
            cout<<a[i]<<" - "<<b[i]<<" = "<<a[i]-b[i]<<endl;
        else
            cout<<a[i]<<" * "<<b[i]<<" = "<<a[i]*b[i]<<endl;
    }

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