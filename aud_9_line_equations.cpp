#include<bits/stdc++.h>
using namespace std;
struct point{
    long long x,y;
    bool operator<(const point &p)const{
        return x<p.x || (x==p.x && y<p.y);
    }
};
int sign(point p1, point p2,point p3){
    point v12{p2.x - p1.x, p2.y - p1.y};
    point v13{p3.x - p1.x, p3.y - p1.y};
    long long d = v12.x * v13.y - v13.x * v12.y;
    if(d==0)return 0;
    if(d<0)return -1;
    return 1;
}
bool intersection(point p1,point p2,point p3,point p4){
    int sign_p3_s12 = sign(p1, p2, p3);
    int sign_p4_s12 = sign(p1, p2, p4);
    int sign_p1_s34 = sign(p3, p4, p1);
    int sign_p2_s34 = sign(p3, p4, p2);
    if(!sign_p1_s34 && !sign_p2_s34 && !sign_p3_s12 && !sign_p4_s12){
        long long x1 = p1.x, x2 = p2.x, x3 = p3.x, x4 = p4.x;
        long long y1 = p1.y, y2 = p2.y, y3 = p3.y, y4 = p4.y;
        if (x1 == x2 && x2 == x3 && x3 == x4) {
            swap(x1, y1);
            swap(x2, y2);
            swap(x3, y3);
            swap(x4, y4);
        }
        long long min12 = min(x1, x2);
        long long max12 = max(x1, x2);
        long long min34 = min(x3, x4);
        long long max34 = max(x3, x4);
        if(max12 < min34) return false;
        if(max34 < min12) return false;
        return true;
    }else{
        if(sign_p1_s34 == sign_p2_s34)
            return false;
        if(sign_p3_s12 == sign_p4_s12)
            return false;
        return true;
    }
}
bool check_if_inside(point p, vector<point> v){
    point ray_end = {(int)2e9, p.y+1};
    int n = v.size();
    int cnt = 0;
    for(int i = 0 ; i < n ; i ++){
        point p1 = v[i];
        point p2 = v[(i+1)%n];
        if(intersection(p, ray_end, p1, p2)){
            cnt++;
        }
    }
    return cnt % 2;
}
vector<point> convex_hull(vector<point> points){
    int n=points.size();
    sort(points.begin(), points.end());
    vector<point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    for(int i = 2 ; i < n ; i ++) {
        while (hull.size() > 2 && sign(hull.end()[-2], hull.back(), points[i]) >= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    return hull;
}
int main(){
    int n;
    cin>>n; // n = 4;
    vector<point> p(n);
    for(int i = 0 ; i < n ; i ++){
        cin>>p[i].x>>p[i].y;
    }
}