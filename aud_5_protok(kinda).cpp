#include<bits/stdc++.h>
using namespace  std;
vector<vector<pair<int,int>> > neg;

int n, m;
vector<int> dijkstra_max_single_flow(int s){
    vector<int> protok(n, 0);
    protok[s] = 1e9;
    priority_queue<pair<int,int> > pq;
    pq.push({protok[s],s});
    while(!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();
        int protok_c = current.first;
        int ind = current.second;
        if (protok_c != protok[ind])continue;
        for (int i = 0; i < neg[ind].size(); i++) {
            int neg_ind = neg[ind][i].first;
            int path_neg_protok = neg[ind][i].second;
            int new_neg_protok = min(path_neg_protok, protok_c);
            if (new_neg_protok > protok[neg_ind]) {
                protok[neg_ind] = new_neg_protok;
                pq.push({new_neg_protok, neg_ind});
            }
        }
    }
    return protok;
}

int main(){
    cin>>n>>m;
    neg.resize(n);
    for(int i = 0,a,b,c ; i < m ; i ++){
        cin>>a>>b>>c;
        neg[a].push_back(make_pair(b, c));
        neg[b].push_back(make_pair(a, c));
    }
    int s = 0;
    vector<int> distances = dijkstra_max_single_flow(s);
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

/*
6 8
0 1 2
0 2 5
1 2 3
1 3 4
2 3 2
2 4 7
3 5 8
4 5 4

 */