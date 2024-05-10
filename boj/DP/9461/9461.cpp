#include <iostream>
using namespace std;

long long dp[100];

long long padovan(int num){
    if(dp[num])
        return dp[num];
    else{
        dp[num] = padovan(num-2) + padovan(num-3);
        return dp[num];
    }
}

int main(){
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    int cycle;
    scanf("%d", &cycle);
    printf("%d", dp[11111]);
    while(cycle--){
        int n;
        scanf("%d", &n);

        if(dp[n])
            printf("%lld\n", dp[n]);
        else
            printf("%lld\n", padovan(n));
    }
    
    return 0;
}