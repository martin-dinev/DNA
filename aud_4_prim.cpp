#include<bits/stdc++.h>
using namespace std;
#define MAX_N 10000
struct edge{
    int neg_cost;
    int cost;
    int a,b;
    bool operator<(const edge& other) const{
        return neg_cost<other.neg_cost;
    }
};
vector<pair<int,int> > edges[MAX_N];
int n,m;
vector<edge> prim(){
    int pocetok = 0;
    set<int> vnatre;
    // set<int> nadvor;
    vnatre.insert(pocetok);
    // for(int i = 0 ; i < n ; i ++){
    //     if(i!=pocetok)
    //         nadvor.insert(i);
    // }
    priority_queue<edge> pq;
    int posledno_dodadeno = 0;
    vector<edge> rez;

    int brojac = 0;
    do{
        for(int i = 0 ; i < edges[posledno_dodadeno].size() ; i ++){
            int sosed = edges[posledno_dodadeno][i].first;
            int cena = edges[posledno_dodadeno][i].second;
            if(vnatre.count(sosed)) continue;
            pq.push({-cena, cena, posledno_dodadeno, sosed});
        }

        edge rebro{};
        do{
            rebro = pq.top();
            pq.pop();
        }while( vnatre.count(rebro.a) && vnatre.count(rebro.b) );
        
        posledno_dodadeno = rebro.b;
        vnatre.insert(posledno_dodadeno);
        rez.push_back(rebro);
    }while(++brojac<n-1);

    // for(int p = 0 ; p < n-1 ; p ++ ){
    //     int cost_min = 1e9;
    //     int a_min,b_min;

    //     // izmini site rebra
    //     for(int teme_vnatre: vnatre){
    //         int broj_na_rebra = edges[teme_vnatre].size();
    //         for(int i = 0 ; i < broj_na_rebra ; i ++){
    //             int sosed = edges[teme_vnatre][i].first;
    //             if(!nadvor.count(sosed))continue;
    //             int cena = edges[teme_vnatre][i].second;
    //             if (cena<cost_min){
    //                 cost_min = cena;
    //                 a_min = teme_vnatre;
    //                 b_min = sosed;
    //             }
    //         }
    //     }

    //     //otkako kje go najdeme dodadi go vo drvoto
    //     vnatre.insert(b_min);
    //     nadvor.erase(b_min);
    //     rez.push_back({a_min, b_min, cost_min});
    // }
    return rez;
}
int main(){
    cin>>n>>m;
    for(int i = 0 ; i < m ; i ++){
        int a,b,cost;
        cin>>a>>b>>cost;
        edges[a].push_back({b,cost});
        edges[b].push_back({a,cost});
    }
    vector<edge> mst = prim();
    for(int i = 0 ; i < mst.size() ; i ++){
        cout<<mst[i].a<<" "<<mst[i].b<<" "<<mst[i].cost<<endl;
    }
}

/*
5 8
0 1 4
0 2 2
1 2 1
1 3 2
1 4 3
2 3 4
2 4 5
3 4 1
*/