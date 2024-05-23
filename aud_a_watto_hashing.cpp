#include<bits/stdc++.h>

using namespace std;
long long a1 = 1000000007;
long long b1 = 1000000009;

long long a2 = 999999937;
long long b2 = 999999929;

map<int, bool> mp1;
map<int, bool> mp2;

int calc_hash(const string &s, long long a, long long b) {
    long long hv = 0;
    long long a_pwr = 1;
    for (int i = 0; i < s.length(); i++) {
        hv += a_pwr * (s[i] - 'a' + 1);
        a_pwr *= a;
        a_pwr %= b;
    }
    hv %= b;
    return (int) hv;
}

void add(string s) {
    int hv1 = calc_hash(s, a1, b1);
    int hv2 = calc_hash(s, a2, b2);
    mp1[hv1] = true;
    mp2[hv2] = true;
}

bool check(int hv1, int hv2) {
    return mp1[hv1] && mp2[hv2];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        add(s);
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        long long hv1 = calc_hash(s, a1, b1), nhvA1, nhvB1, nhvC1;
        long long hv2 = calc_hash(s, a2, b2), nhvA2, nhvB2, nhvC2;
        long long a_pwr_1 = 1, a_pwr_2 = 1;

        bool found = false;

        for (int i = 0; i < s.length(); i++) {
            long long base_hv_1 = hv1 - a_pwr_1 * (s[i] - 'a' + 1);
            nhvA1 = (base_hv_1 + a_pwr_1 * ('a' - 'a' + 1)) % b1;
            nhvB1 = (base_hv_1 + a_pwr_1 * ('b' - 'a' + 1)) % b1;
            nhvC1 = (base_hv_1 + a_pwr_1 * ('c' - 'a' + 1)) % b1;


            long long base_hv_2 = hv2 - a_pwr_2 * (s[i] - 'a' + 1);
            nhvA2 = (base_hv_2 + a_pwr_2 * ('a' - 'a' + 1)) % b2;
            nhvB2 = (base_hv_2 + a_pwr_2 * ('b' - 'a' + 1)) % b2;
            nhvC2 = (base_hv_2 + a_pwr_2 * ('c' - 'a' + 1)) % b2;

            if (s[i] != 'a') {
                if (check(nhvA1, nhvA2)) {
                    found = true;
                    break;
                }
            }
            if (s[i] != 'b') {
                if (check(nhvB1, nhvB2)) {
                    found = true;
                    break;
                }
            }
            if (s[i] != 'c') {
                if (check(nhvC1, nhvC2)) {
                    found = true;
                    break;
                }
            }

            a_pwr_1 *= a1;
            a_pwr_1 %= b1;
            a_pwr_2 *= a2;
            a_pwr_2 %= b2;
        }
        if (!found) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}