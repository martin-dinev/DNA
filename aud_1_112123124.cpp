#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int max = 0;
    vector<int> numbers;
    int window_size = 1;
    for(int i = 0 ; i < 14 ; i ++){
        cin>>n;
        for( ; numbers.size() < n ; window_size++){
            for(int j = 1 ; j <= window_size ; j ++){
                numbers.push_back(j);
            }
        }
        cout<<numbers[n-1]<<" ";
    }
}