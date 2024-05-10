#include <iostream>
#include <cmath>
using namespace std;

// 100,000 * 100,000 = 10,000,000,000 

int base_arr[100001];
int dp[100001];

int main(){

    int cycle, temp_max;

    scanf("%d", &cycle);

    for (int i = 1; i <= cycle; i++)
        scanf("%d", &base_arr[i]);

    temp_max = base_arr[1];
    dp[0] = 0;
    dp[1] = base_arr[1];
 
    for (int i = 1; i <= cycle; i++){
        dp[i] = max(dp[i-1] + base_arr[i], base_arr[i]);
        temp_max = max(temp_max, dp[i]);
    }

    printf("%d\n", temp_max);

    return 0;
}