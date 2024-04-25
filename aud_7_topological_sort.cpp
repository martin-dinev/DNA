#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > ng(26);
vector<int> vis(26,0);
vector<int> ord;
void dfs(int ind){
    vis[ind] = 1;
    for(int i = 0 ; i < ng[ind].size() ; i ++){
        if(vis[ng[ind][i]] == 0){
            dfs(ng[ind][i]);
        }else if(vis[ng[ind][i]] == 1){
            cout<<"Impossible\n";
            exit(0);
        }else{
            continue;
        }
    }
    vis[ind] = 2;
    ord.push_back(ind);
}

int main(){
    int n;
    cin>>n;
    string pr="";
    for(int i = 0 ; i < n ; i ++){
        string t;
        cin>>t;
        if(i!=0){
            int j = 0;
            for( ; j < t.size() && j < pr.size() ; j++ ){
                if(t[j] != pr[j])break;
            }
            if(j == t.size() || j == pr.size()){
                if(j==pr.size()){

                }else{
                    cout<<"Impossible\n";
                    return 0;
                }
            }else{
                char a = pr[j];
                char b = t[j];
                ng[a-'a'].push_back(b-'a');
            }
        }
        pr=t;
    }

    for(int i = 25 ; i >= 0 ; i --){ // order doesn't matter
        if(vis[i] == 0){
            dfs(i);
        }
    }

    reverse(ord.begin(),ord.end());
    for(int i = 0 ; i < ord.size() ; i ++){
        cout<<char(ord[i]+'a');
    }

}