#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int max = 0;
    // vector<int> ones_pos;
    // for(int ws = 1 ; ws <= 100 ; ws ++){
    //     if(ws == 1)
    //         ones_pos.push_back(0);
    //     else
    //         ones_pos.push_back( ones_pos.back() + ws-1 );
    // }
    // vector<int> numbers;
    // int window_size = 1;
    for(int i = 0 ; i < 14 ; i ++){
        cin>>n; n --;
        // for( ; numbers.size() < n ; window_size++){
        //     for(int j = 1 ; j <= window_size ; j ++){
        //         numbers.push_back(j);
        //     }
        // }
        // cout<<numbers[n-1]<<endl;

        int ws = (-1 + sqrt(8*n + 1)) / 2;

        cout << n - ws * (ws+1) / 2 + 1 << " ";


    }
}

// 123456789101112131415161718192021
// 012345678901234567890123465789012
//           1         2         3 