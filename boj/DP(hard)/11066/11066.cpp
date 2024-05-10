#include <iostream>
using namespace std;

int sum[501];
int dp[501][501];

void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return;
}
int main(){

    fast_io();

    int test_T, nums_K, n; // test_T: number of cycle, nums_K: number of data, n: data
    cin >> test_T;

    sum[0] = 0;

    for (int cy = 0; cy < test_T; cy++){
        cin >> nums_K;

        for (int j = 1; j <= nums_K; j++){
            cin >> n;
            sum[j] = sum[j-1] + n;
        }

        for (int row = 1; row < nums_K; row++){
            int i = 1;
            int j = row+1;
            for(int l = 0; l < nums_K-row; l++){
                dp[i][j] = 1e9;
                for (int m = j-row; m <= j-1; m++)
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m+1][j] + sum[j] - sum[i-1]);
                i++;
                j++; 
            }
        }
        cout << dp[1][nums_K] <<"\n";
    }

    return 0;
}