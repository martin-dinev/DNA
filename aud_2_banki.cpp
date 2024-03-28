#include<bits/stdc++.h>
using namespace std;
// int A[100][100];
vector<vector<int> > A;
vector<vector<int> > dp;
int MAX = 0;
int n,m;
int recursive(int level, int limit, int sum_before){
    for(int i = 0 ; i < level ; i ++)cout<<" ";
    cout << level <<" " <<limit<<" "<<sum_before<<endl;
    if(level == m){
        MAX = max(MAX, sum_before);
        return 0;
    }
    
    for(int money = 0 ; money <= limit ; money ++ ){
        int next_limit = limit - money;
        int next_sum = sum_before + A[level][money];
        recursive(level+1, next_limit, next_sum);
    }   
    return 0;
}
int main(){
    cin>>n>>m;
    A.resize(m, vector<int> (n+1, 0));
    dp.resize(m, vector<int> (n+1, 0));
    for(int i = 0 ; i < m ; i ++){
        A[i][0] = 0;
        for(int denari = 1 ; denari <= n ; denari ++){
            cin>>A[i][denari];
        }
    }
    // int limit_i = 4;
    // int sum_before_i = 0;
    // for(int i = 0 ; i <= limit_i ; i ++){
    //     int limit_j = limit_i-i;
    //     int sum_before_j = sum_before_i + A[0][i];
    //     for(int j = 0 ; j <= limit_j ; j ++){
    //         int limit_k = limit_j-j;
    //         int sum_before_k = sum_before_j + A[1][j];
    //         for(int k = 0 ; k <= limit_k ; k ++){
    //             int sum = sum_before_k+A[2][k];
    //             MAX = max(MAX, sum);
    //         }
    //     }
    // }

    // recursive(0, n, 0);  

    for(int level = 0 ; level < m ; level ++){
        for(int limit = 0 ; limit <= n ; limit ++){
            int max_sum = dp[level][limit];
            for(int money = 0 ; money <= limit ; money ++ ){
                int next_limit = limit - money;
                int next_sum = max_sum + A[level][money];
                if(level+1<m)
                    dp[level+1][next_limit] = 
                        max( 
                            dp[level+1][next_limit],
                            next_sum
                        );
                else
                    MAX = max(MAX, next_sum);
            }   
        }
    }  
    
    
    


    cout<<MAX;
}