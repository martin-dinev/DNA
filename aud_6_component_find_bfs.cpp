#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > ng;
int main(){
    int n,q;
    cin>>n>>q;
    vector<vector<int> > queries(q);
    for(int i = 0,t,a,b ; i < q ; i ++){
        cin>>t>>a>>b;
        queries[i] = {t,a,b};
    }
    sort(queries.begin(),queries.end());
    ng.resize(n);
    int t2 = 0;
    for(int i = 0 ; i < q ; i ++){
        if(queries[i][0] == 1){t2=i;break;}
        int a = queries[i][1],b = queries[i][2];
        ng[a].push_back(b);
        ng[b].push_back(a);
    }
    vector<int> component(n, -1);
    int component_count = -1;
    for(int i = 0 ; i < n ; i ++){
        if(component[i] != -1)continue;
        component_count++;
        component[i] = component_count;
        queue<int> q;
        q.push(i);
        while(q.size()){
            int c = q.front();
            q.pop();
            for(int j = 0 ; j < ng[c].size() ; j ++){
                if(component[ng[c][j]] != -1)continue;
                component[ng[c][j]] = component_count;
                q.push(ng[c][j]);
            }
        }
    }

    for(int i = t2 ; i < q ; i ++){
        int a = queries[i][1],b = queries[i][2];
        int c1 = component[a],c2 = component[b];
        cout << a <<" " <<b<<" " << (c1==c2)<<" "<< c1 << " " << c2 << endl;
    }
}