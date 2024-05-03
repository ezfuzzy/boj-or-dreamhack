#include <iostream>
using namespace std;

void fastIo(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int nums_N, dp[1000]; // <= 1000

int main(){
    fastIo();
    cin >> nums_N;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    dp[4] = 1;

   
    for (int i = 5; i <= nums_N; i++){
        if(dp[i-1] && dp[i-3] && dp[i-4])
            dp[i] = 0;
        else
            dp[i] = 1;
    }

    if(dp[nums_N])
        cout << "SK" << '\n';
    else
        cout << "CY" << '\n';
    return 0;
}
