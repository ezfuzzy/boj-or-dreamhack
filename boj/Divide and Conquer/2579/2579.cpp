#include <iostream>
using namespace std;
// 1. diff : 1~2 ** 
// 2. 연속 +1 2번 불가능(연속 3계단) (시작점은 x)
// 3. end index는 필수 들려야함 
// 계단 수 <= 300, 각 계단의 정수 <= 10,000 
int stairs[301];
int dp[301];


int main(){

    int cycle;
    scanf("%d", &cycle);
    
    for (int i = 1; i <= cycle; i++)
        scanf("%d", &stairs[i]);
    
    dp[1] = stairs[1];
    dp[2] = stairs[1]+stairs[2];

    for (int i = 3; i <= cycle; i++)
        dp[i] = max(dp[i-2], dp[i-3]+stairs[i-1]) + stairs[i];
    
    printf("%d", dp[cycle]);

    return 0;
}