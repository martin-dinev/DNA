#include <bits/stdc++.h>
using namespace std;
void solve();
int main(){
    int t;cin>>t;
    while(t--) solve();
}
vector<vector<int> > same;
vector<vector<int> > dif;

void solve(){
    int n,q;
    cin>>n>>q;
    same.clear();dif.clear();
    same.resize(n);dif.resize(n);
    for(int i = 0,tq,a,b ; i < q ; i ++){
        cin>>tq>>a>>b;a--;b--;
        if(tq == 1){
            dif[a].push_back(b);
            dif[b].push_back(a);
        }else{
            same[a].push_back(b);
            same[b].push_back(a);
        }
    }
    vector<bool> vis(n,false);
    vector<int> tip(n);
    int rez = 0;
    for(int i = 0 ; i < n ; i ++){
        if(vis[i])continue;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        tip[i] = 1;
        int tip1 = 1;
        int tip2 = 0;
        while(!q.empty()){
            int u = q.front();q.pop();
            for(int v : same[u]){
                if(vis[v]){
                    if(tip[v] != tip[u]){
                        cout<<"-1\n";
                        return;
                    }
                }else{
                    vis[v] = true;
                    tip[v] = tip[u];
                    if(tip[v] == 1)tip1++;
                    else tip2++;
                    q.push(v);
                }
            }
            for(int v : dif[u]){
                if(vis[v]){
                    if(tip[v] == tip[u]){
                        cout<<"-1\n";
                        return;
                    }
                }else{
                    vis[v] = true;
                    tip[v] = 3 - tip[u];
                    if(tip[v] == 1)tip1++;
                    else tip2++;
                    q.push(v);
                }
            }
        }

        rez += max(tip1,tip2);

    }
    cout<<rez<<endl;

}