#include <iostream>
using namespace std;
// height : 1 ~ 500 

int dp[501][501];

int main(){

    int cycle, temp_cycle, num, temp_max = 0;
    scanf("%d", &cycle);
    
    for (int i = 1; i <= cycle; i++)
    {
        temp_cycle = i;
        for (int j = 1; j <= temp_cycle; j++)
        {
            scanf("%d", &num);

            dp[i][j] = max(dp[i-1][j-1]+num, dp[i-1][j]+num);
            temp_max = max(dp[i][j], temp_max);
        }

    }
    printf("%d\n", temp_max);

    return 0;
}