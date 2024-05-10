#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];

int main() {

    int cycle, temp_max = 0;
    scanf("%d", &cycle);

    for (int i = 1; i <= cycle; i++)
        scanf("%d", &arr[i]);
    
    for (int i = 1; i <= cycle; i++){
        dp[i] = 1;

        for (int j = 1; j < i; j++)
            if(arr[i] < arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
            
        temp_max = max(temp_max, dp[i]);
    }
    
    printf("%d\n", temp_max);
    return 0;
}