#include <iostream>
#include <cmath>
using namespace std;

// 2 <= 집의 수 <= 1,000
// 둘째줄부터는 n개의 줄에는 r, g, b 로 칠하는 비용이 써져있다. (비용 <= 1000)
// 연속된 집은 색이 같아선 안된다. 

int base[10001];
int dp[10001][3];

int main(){

    int cycle, r, g, b, min_cost;
    scanf("%d", &cycle);

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    for (int i = 1; i <= cycle; i++)
    {
        scanf("%d %d %d", &r, &g, &b);
        
        dp[i][0] = min(dp[i-1][1] + r, dp[i-1][2] + r);
        dp[i][1] = min(dp[i-1][0] + g, dp[i-1][2] + g);
        dp[i][2] = min(dp[i-1][0] + b, dp[i-1][1] + b);

    }
    min_cost = min(min(dp[cycle][0], dp[cycle][1]), dp[cycle][2]);
    printf("%d\n", min_cost);
}