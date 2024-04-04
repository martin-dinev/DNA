#include<bits/stdc++.h>
using namespace  std;
vector<vector<pair<int,int>> > neg;

int n, m;
vector<int> bellman_ford(int s){
    vector<int> dist(n, 1e9);
    vector<bool> nc(n, false);
    dist[s] = 0;
    for(int i = 0 ; i < n ; i ++){
        for(int ind = 0 ; ind < n ; ind++){
            for(int j = 0 ; j < neg[ind].size() ; j ++){
                int ng = neg[ind][j].first;
                int cost = neg[ind][j].second;
                int new_ng_dist = dist[ind] + cost;
                if(new_ng_dist < dist[ng])
                    dist[ng] = new_ng_dist;
            }
        }
    }
    vector<int> n_dist = dist;
    for (int i = 0; i < n; i++) {
        for (int ind = 0; ind < n; ind++) {
            for (int j = 0; j < neg[ind].size(); j++) {
                int ng = neg[ind][j].first;
                int cost = neg[ind][j].second;
                int new_ng_dist = n_dist[ind] + cost;
                if (new_ng_dist < n_dist[ng]){
                    n_dist[ng] = new_ng_dist;
                    nc[ng] = true;
                }
            }
        }
    }

    for(int i = 0 ; i < n ; i ++){
        if(nc[i])
            dist[i] = -1e9;
    }

    return dist;
}

int main(){
    cin>>n>>m;
    neg.resize(n);
    for(int i = 0,a,b,c ; i < m ; i ++){
        cin>>a>>b>>c;
        neg[a].push_back(make_pair(b, c));
//        neg[b].push_back(make_pair(a, c));
    }
    int s = 0;
    vector<int> distances = bellman_ford(s);
    for(int i = 0 ; i < n ; i ++){
        cout<<distances[i]<<" ";
    }
    //0 2 5 6 12
    //0 2 5 7 12 16
}

/*
5 9
0 1 4
0 2 2
2 1 1
1 2 3
1 3 2
1 4 3
2 3 4
2 4 5
4 3 0

 */