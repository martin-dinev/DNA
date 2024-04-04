#include<bits/stdc++.h>
using namespace  std;
vector<vector<pair<int,double>> > neg;

int n, m;
vector<double> dijkstra(int s){
    vector<double> dist(n, 1e9);
    dist[s] = 0;
    priority_queue<pair<int,int> > pq;
    pq.push({-0,s});
    while(!pq.empty()) {
        pair<double, int> current = pq.top();
        pq.pop();
        int dist_c = -current.first;
        int ind = current.second;
        if (dist_c != dist[ind])continue;
        for (int i = 0; i < neg[ind].size(); i++) {
            int neg_ind = neg[ind][i].first;
            double path_neg_cost = neg[ind][i].second;
            double new_neg_dist = path_neg_cost + dist_c;
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
    double rastojanie, max_speed;
    for(int i = 0,a,b,c ; i < m ; i ++){
        cin>>a>>b>>rastojanie>>max_speed;
        neg[a].push_back(make_pair(b, rastojanie/max_speed));
//        neg[b].push_back(make_pair(a, c));
    }
    int s;
    cin>>s;
    vector<double> distances = dijkstra(s);
//    for(int i = 0 ; i < n ; i ++){
//        cout<<distances[i]<<" ";
//    }
    int f;
    cin>>f;
    cout<<distances[f];
}
