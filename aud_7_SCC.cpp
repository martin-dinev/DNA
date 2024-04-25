#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > ng;
vector<vector<int> > ng2;
vector<bool> vis;
vector<int> red;
void dfs(int ind){
    vis[ind] = 1;
    for(int i = 0 ; i < ng[ind].size() ; i ++){
        if(!vis[ng[ind][i]]){
            dfs(ng[ind][i]);
        }
    }
    red.push_back(ind);
}
int main(){
    int n,m;cin>>n>>m;
    ng.resize(n);
    ng2.resize(n);
    for(int i = 0,a,b ; i < m ; i ++){
        cin>>a>>b;a--;b--;
        ng[a].push_back(b);
        ng2[b].push_back(a);
    }

    vis.resize(n);
    for(int i = 0 ; i < n ; i ++){
        if(vis[i])continue;
        dfs(i);
    }

    reverse(red.begin(),red.end());

    vis = vector<bool> (n,0);
    vector<int> pass = red;
    red.clear();
    vector<int> comp(n);
    int br = 0;
    ng = ng2;
    for(int i = 0 ; i < n ; i ++){
        int c = pass[i];
        if(vis[c])continue;
        int pos = red.size();
        dfs(c);
        br++;
        for(int j = pos ; j < red.size() ; j ++){
            comp[red[j]] = br;
        }
    }
    

    for(int i = 0 ; i < n ; i ++){
        cout<<i+1<<" ";
    }
    cout<<endl;

    for(int i = 0 ; i < n ; i ++){
        cout<<comp[i]<<" ";
    }


}   