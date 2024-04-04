#include<bits/stdc++.h>
using namespace  std;
vector<vector<pair<int,int>> > neg;

int n, m;
vector<int> dijkstra(int s){
    vector<int> dist(n, 1e9);
    dist[s] = 0;
    priority_queue<pair<int,int> > pq;
    pq.push({-0,s});
    while(!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();
        int dist_c = -current.first;
        int ind = current.second;
        if (dist_c != dist[ind])continue;
        for (int i = 0; i < neg[ind].size(); i++) {
            int neg_ind = neg[ind][i].first;
            int path_neg_cost = neg[ind][i].second;
            int new_neg_dist = path_neg_cost + dist_c;
            if (new_neg_dist < dist[neg_ind]) {
                dist[neg_ind] = new_neg_dist;
                pq.push({-new_neg_dist, neg_ind});
            }
        }
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
    vector<int> distances = dijkstra(s);
    for(int i = 0 ; i < n ; i ++){
        cout<<distances[i]<<" ";
    }
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