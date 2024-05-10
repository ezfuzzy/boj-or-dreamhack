#include <iostream>
using namespace std;

int arr[10001];
int dp[10001];

int main(){

    int cycle;
    scanf("%d", &cycle);
    for (int i = 1; i <= cycle; i++)
        scanf("%d", &arr[i]);
    
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];


    for (int i = 3; i <= cycle; i++)
        dp[i] = max(max(dp[i-3] + arr[i-1] + arr[i], dp[i-2] + arr[i]), dp[i-1]);
    
    printf("%d\n", dp[cycle]);

    return 0;
}