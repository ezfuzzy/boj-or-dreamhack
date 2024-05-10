#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int nums_N, cy_temp_num, ans=100, dp[50001];
int main(){

  cin >> nums_N; // <=50,000r
  
  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= nums_N; i++){
    dp[i] = 100;
    if (i - pow(int(sqrt(i)), 2)) {
      int idx = 1;
      while(idx < sqrt(i)){
        int temp_idx = pow(idx, 2);
        dp[i] = min(dp[i], dp[temp_idx] + dp[i-temp_idx]);
        idx++;
      }
    }
    else// perfect square number
      dp[i] = 1;
  }
 
  std::cout << dp[nums_N] << '\n';
  return 0;
}

// int main(){

//   cin >> nums_N; // <=50,000r
  
//   cy_temp_num = int(sqrt(nums_N));

//   while(cy_temp_num){

//     int cy_nums_N = nums_N, ans_count=0, temp_num;

//     while(cy_nums_N){
//       if (cy_nums_N == nums_N)
//         cy_nums_N -= pow(cy_temp_num, 2);
//       else {
//         temp_num = int(sqrt(cy_nums_N));
//         cy_nums_N -= pow(temp_num, 2);
//       }
//       ans_count++;
//     }
//     ans = min(ans, ans_count);
//     cy_temp_num--;
//   }

//   cout << ans << '\n';
//   return 0;
// }