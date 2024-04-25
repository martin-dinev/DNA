#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > ng;
vector<int> dist;
vector<bool> vis;

void dfs(int ind, int par){
    if(par!=-1)
        dist[ind] = dist[par] + 1;
    else
        dist[ind] = 0;
    vis[ind] = true;
    for(int i = 0 ; i < ng[ind].size() ; i ++){
        // if(ng[ind][i] == par)continue; // if working with trees
        if(vis[ng[ind][i]])continue;
        dfs(ng[ind][i],ind);
    }
}

int main(){
    int n,m,start;
    cin>>n>>m>>start;
    ng.resize(n);
    for(int i = 0,a,b ; i < m ; i ++){
        cin>>a>>b;
        ng[a].push_back(b);
        ng[b].push_back(a);
    }
    dist.resize(n, -1);
    vis.resize(n,false);
    
    dfs(start, -1);

    for(int i = 0 ; i < n ; i ++){
        cout<<dist[i]<<" ";
    }
}