#include <iostream>

using namespace std;

void fastIo(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

int nums_N, nums_M; // <= 100,000
int arr[100001], dp[100001], sum=0;
// dp[i]: i번쨰 숫자까지 합
int main(){
  fastIo();
  cin >> nums_N >> nums_M;

  for (int i = 1; i <= nums_N; i++){
    cin >> arr[i];
    sum+=arr[i];
    dp[i] = sum;
  }
  
  for (int i = 0; i < nums_M; i++){
    int left, right, ans=0;
    cin >> left >> right;
    ans = dp[right] - dp[left-1];
    
    cout << ans << '\n';
  }
  return 0;
}