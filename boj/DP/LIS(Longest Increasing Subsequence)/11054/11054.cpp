#include <iostream>
using namespace std;

int arr[1001];
int dp[1001][3];
// [1] : + / [2] : - 
int main(){

    int cycle, temp_max = 0;
    scanf("%d", &cycle);

    for (int i = 1; i <= cycle; i++)
        scanf("%d", &arr[i]);

    // longgest + 
    for (int i = 1; i <= cycle; i++){
        dp[i][1] = 1;
        dp[i][2] = 1;

        for (int j = 1; j < i; j++)
            if (arr[i] > arr[j])
                dp[i][1] = max(dp[i][1], dp[j][1] + 1);

        temp_max = max(temp_max, dp[i][1]);
    }

    // longgest -
   for (int i = cycle; i >= 1; i--){

        for (int j = i; j <= cycle; j++)
            if (arr[i] > arr[j])
                dp[i][2] = max(dp[i][2], dp[j][2] + 1);
            
        temp_max = max(temp_max, dp[i][2]);
    }
    
    // biotonic 
    for (int i = 1; i <= cycle; i++)
        temp_max = max(temp_max, dp[i][1] + dp[i][2] - 1);
    
    printf("%d\n", temp_max);
    
    return 0;
}