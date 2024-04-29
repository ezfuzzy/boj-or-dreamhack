#include <iostream>
using namespace std;

int nums_M, nums_N, arr[501][501], available_H, dp[501][501][501];

void fastIo(){
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main(){
    fastIo();
    cin >> nums_M >> nums_N;

    for (int i = 0; i < nums_M; i++)
        for (int j = 0; j < nums_N; j++)
            cin >> arr[i][j];
    
    
    

    return 0;
}