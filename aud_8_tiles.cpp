#include <bits/stdc++.h>
using namespace std;



struct edge {
    int from, to, cap;
};
vector<edge> edges;
vector<vector<int> > ng;
vector<int> parent;

bool bfs(int s, int t);
int fordFulkerson(int s, int t);
int n,m,k;


map<pair<int,int>, int> mp;
int get_ind(pair<int,int> x){
    if(mp.find(x) == mp.end()){
        mp[x] = mp.size();
    }
    return mp[x];
    // less complicated version
    // return x.first * n + x.second;
}

void add_edge(int from, int to){
    edges.push_back({from,to,1});
    edges.push_back({to,from,0});
    ng[from].push_back(edges.size()-2);
    ng[to].push_back(edges.size()-1);
}

int main(){
    cin>>n>>m>>k;
    ng.resize(n*m+2);
    parent.resize(ng.size());


    vector<vector<bool> > mt(n,vector<bool>(m,false));
    for(int i = 0 ; i < k ; i ++){
        int pi,pj;
        cin>>pi>>pj;
        mt[pi][pj] = true;
    }

    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            if(mt[i][j]) continue;
            if((i+j)%2) continue;
            for(int k = 0 ; k < 4 ; k ++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                if(mt[ni][nj]) continue;
                add_edge(get_ind({i,j}),get_ind({ni,nj}));
            }
        }
    }

    int source = n * m;
    int sink = source + 1;

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            if(mt[i][j]) continue;
            if((i+j)%2 == 0)
                add_edge(source, get_ind({i,j}));
            else
                add_edge(get_ind({i,j}),sink);
        }
    }

    int rez = fordFulkerson(source,sink);
    if(rez*2 + k == n*m){
        cout<<"Yes\n";
    }
    else{
        cout<<"No "<< n*m - (rez*2 + k) <<"\n";
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
