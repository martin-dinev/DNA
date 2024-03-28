#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 12;
    int dp[n+1] = {1,1,0};
    for(int i = 2; i <= n ; i += 2)    {
        dp[i] = 0;
        for(int j = 0 ; j < i ; j += 2){
            dp[i] += dp[j] * dp[i-j-2];
        }
    }
    for(int i = 0 ; i <= n ; i += 2){
        cout<<i<<": "<<dp[i];
        cout<<endl;
    }
}