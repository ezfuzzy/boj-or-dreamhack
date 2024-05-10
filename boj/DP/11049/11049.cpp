#include <iostream>
#include <cmath>
using namespace std;
int nums_N, dp[501][501];
pair<int, int> arr[501];

void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
}
int product(int i, int m, int j){
    return (arr[i].first*arr[m].second*arr[j].second);
}
int main(){

    fast_io();
    cin >> nums_N;

    for (int i = 1; i <= nums_N; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    for (int main_cycle = 1; main_cycle < nums_N; main_cycle++){
        int i = 1;
        int j = main_cycle+1;
        for (int sub_cycle = 0; sub_cycle < nums_N - main_cycle; sub_cycle++){
            dp[i][j] = pow(2,31)-1;
            for (int leaf_cycle = j-main_cycle; leaf_cycle <= j-1; leaf_cycle++)
                dp[i][j] = min(dp[i][j], dp[i][leaf_cycle] + dp[leaf_cycle+1][j] + product(i,leaf_cycle,j));
            i++;
            j++;
        }
    }
    cout << dp[1][nums_N] << "\n";  
    return 0;
}