#include <bits/stdc++.h>

using namespace std;

vector<int> z(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0, min(z[i - x], y - i + 1));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            x = i;
            y = i + z[i];
            z[i]++;
        }
    }
    return z;
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> z_values = z(s);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (z_values[i] + i == n) {
            if (mx >= z_values[i]) {
                cout << s.substr(0, z_values[i]);
                return 0;
            }
        }
        mx = max(mx, z_values[i]);
    }
    cout << "Just a legend";
}