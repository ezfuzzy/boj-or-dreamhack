#include <bits/stdc++.h>
using namespace std;
#define fastIo ios_base::sync_with_stdio(0);cin.tie(0);

int TC, n, ans=0; // n: [1,100,000]

int main(){
  fastIo;

  cin >> TC;

  while(TC--){
    cin >> n;

    int sticker[2][n];
    int dp[2][n];

    for (int i = 0; i < 2; i++)
      for (int j = 0; j < n; j++)
        cin >> sticker[i][j]; // [0,100]
    
    dp[0][0] = sticker[0][0];
    dp[1][0] = sticker[1][0];
    if(n >= 2){
      dp[0][1] = dp[1][0] + sticker[0][1];
      dp[1][1] = dp[0][0] + sticker[1][1];
    }
    for (int j = 2; j < n; j++){
      for (int i = 0; i < 2; i++){
          if(i == 0){
            dp[i][j] = max(dp[1][j-1], dp[1][j-2]) + sticker[i][j];
          } else {
            dp[i][j] = max(dp[0][j-1], dp[0][j-2]) + sticker[i][j];
          }
      }
    }
    cout << max(dp[0][n-1], dp[1][n-1]) << '\n';
  }
  
  return 0;
}