#include <iostream>
using namespace std;
void fastIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
int nums_R, nums_C, x1, y_1, x2, y2, cycle, temp_num; // row, col
// R, C <= 1024 cycle <= 100,000
int arr[1025][1025], dp[1025][1025];
/*
    arr ? 
    dp ? > dp[i][j] = arr[0][0] ~ arr[i][j]까지 요소들의 합
    xxx int ans = dp[x2][y2] - dp[x1][y_1] - dp[y_1][x1] + dp[x1-1][y_1-1] + arr[x1][y_1]*2;
    dp[i][j] = ? 
    if (i == 1)
        dp[i][j] = dp[i-1][j] + arr[i][j]; 
    else if (j == 1)
        dp[i][j] = dp[i][j-1] + arr[i][j]; 
    else
        dp[i][j] = d[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j]; 
    */

int main(){
    fastIO();
    cin >> nums_R >> nums_C;

    for (int idx_R = 1; idx_R <= nums_R; idx_R++) // max about 1,000,000
        for (int idx_C = 1; idx_C <= nums_C; idx_C++){
            cin >> arr[idx_R][idx_C];
            // dp 갱신
            if (idx_R == 1)
                dp[idx_R][idx_C] = dp[idx_R][idx_C-1] + arr[idx_R][idx_C]; 
            else if (idx_C == 1)
                dp[idx_R][idx_C] = dp[idx_R-1][idx_C] + arr[idx_R][idx_C]; 
            else
                dp[idx_R][idx_C] = dp[idx_R][idx_C-1] + dp[idx_R-1][idx_C] - dp[idx_R-1][idx_C-1] + arr[idx_R][idx_C]; 
        }
    

    cin >> cycle;
    for (int i = 0; i < cycle; i++){
        cin >> x1 >> y_1 >> x2 >> y2;
        int ans;
        if (x2 == 1 || y2 == 1) // x1 <= x2 / y_1 <= y2
            ans = dp[x2][y2] - dp[x1][y_1] + arr[x1][y_1]; 
        else
            ans = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y_1-1] + dp[x1-1][y_1-1];
        //  int ans = dp[x2][y2] - dp[x1][y_1] - dp[y_1][x1] + dp[x1-1][y_1-1] + arr[x1][y_1]*2;
        cout << ans << '\n';
    }
    



    return 0;
}