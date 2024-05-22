#include <bits/stdc++.h>
using namespace std;

int n, dp[1001];

int main(){

  cin >> n;

  dp[1] = 1;
  dp[2] = 3;
  
  for (int i = 3; i <= n; i++){
    // dp[i] = (dp[i-1] + 2*dp[i-2]) % 10007;
    if(i%2 == 0)
      dp[i] = (dp[i-1]*2+1) % 10007;
    else
      dp[i] = (dp[i-1]*2-1) % 10007;
  }
  
  cout << dp[n];
  return 0;
}