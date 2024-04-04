#include<bits/stdc++.h>

using namespace std;
vector<vector<int> > dist;

int n, m;

int main() {
    cin >> n >> m;
    dist.resize(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++)dist[i][i] = 0;
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    for (int mid = 0; mid < n; mid++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int new_dist = dist[i][mid] + dist[mid][j];
                if (dist[i][j] == 1e9) {
                    if (new_dist < dist[i][j])
                        dist[i][j] = new_dist;
                } else {
                    if (new_dist != dist[i][j]) {
                        cout << "NO SOLUTION";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "YES SOLUTION";
    vector<int> plati(n, 1e9);
    for (int i = 0; i < n; i++) {
        if (plati[i] == 1e9) {
            plati[i] = 1e6;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] != 1e9) {
                    plati[j] = plati[i] + dist[i][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << plati[i];
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