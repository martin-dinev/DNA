#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 12;
    set<string> s[n+1];
    int dp[n+1];
    s[0] = {""};
    dp[0] = 1;
    s[2] = {"()"};
    dp[2] = 1;
    for(int i = 4; i <= n ; i += 2)    {
        // for(auto x : s[i-2]){
        //     s[i].insert("("+x+")");
        // }
        // for(int j = 2 ; j < i ; j += 2){
        //     for(auto x : s[j]){
        //         for(auto y : s[i-j]){
        //             s[i].insert(x+y);
        //         }
        //     }
        // }
        dp[i] = 0;
        for(int j = 0 ; j < i ; j += 2){
            dp[i] += dp[j] * dp[i-j-2];
            // for(auto x : s[j]){
            //     for(auto y : s[i-j-2]){
            //         s[i].insert("("+x+")"+y);
            //     }
            // }
        }
    }

    for(int i = 0 ; i <= n ; i += 2){
        cout<<i<<": "<<dp[i];
        cout<<endl;
    }

    // for(int i = 2 ; i <= n ; i += 2){
    //     cout<<i<<": ";
    //     for(auto x : s[i]){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
}