#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > ng;
int main(){
    int n,m,start;
    cin>>n>>m>>start;
    ng.resize(n);
    for(int i = 0,a,b ; i < m ; i ++){
        cin>>a>>b;
        ng[a].push_back(b);
        ng[b].push_back(a);
    }

    vector<int> dist(n, -1);
    vector<bool> vis(n,false);
    
    dist[start] = 0;
    vis[start] = true;
    stack<int> q;
    q.push(start);
    while(q.size()){
        int c = q.top();
        q.pop();
        for(int j = 0 ; j < ng[c].size() ; j ++){
            if(vis[ng[c][j]])continue;
            vis[ng[c][j]] = true;
            dist[ng[c][j]] = dist[c]+1;
            q.push(ng[c][j]);
        }
    }

    for(int i = 0 ; i < n ; i ++){
        cout<<dist[i]<<" ";
    }
}