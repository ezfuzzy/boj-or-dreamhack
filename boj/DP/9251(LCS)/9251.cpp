#include <iostream>
#include <string>
using namespace std;

int dp[1001][1001];

int main(){

    string str1, str2;
    int temp_max = 0;

    cin >> str1 >> str2;

    for (int i = 1; i <= str1.length(); i++){
        int temp_weight = 0;
        for (int j = 1; j <= str2.length(); j++){            
            if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            temp_max = max(temp_max, dp[i][j]);
        }
    }
    
    printf("%d\n", temp_max);

    return 0;
}