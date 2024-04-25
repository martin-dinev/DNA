#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<char> > v(n, vector<char> (n));
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++){
            cin>>v[i][j];
        }
    }

    vector<vector<int> > dist(n,vector<int> (n));
    vector<vector<bool> > vis(n,vector<bool> (n,false));

    vis[0][0] = true;
    dist[0][0] = 0;
    queue<pair<int,int> > q;
    q.push({0,0});
    vector<pair<int,int> > ng_dir = {{-1,0},{1,0},{0,-1},{0,1}};
    while(q.size()){
        pair<int,int> c = q.front();q.pop();
        int i = c.first,j = c.second;
        for(auto dir: ng_dir){
            int ni = dir.first + i;
            int nj = dir.second + j;
            if(ni < 0 || nj < 0 || ni >= n || nj >= n || v[ni][nj] == '*') continue;
            if(vis[ni][nj]) continue;
            vis[ni][nj] = true;
            dist[ni][nj] = dist[i][j] + 1;
            q.push({ni,nj});
        }
    }

    if(! vis[n-1][n-1])
        cout<<"-1";
    else
       cout<<dist[n-1][n-1];

}