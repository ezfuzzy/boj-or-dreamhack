#include <iostream>
#include <algorithm>
using namespace std;
int arr[101][2];
int dp[100001][101];

void fast_io(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return;
}

int main(){

    fast_io();

    int nums_N, can_K, ans;
    cin >> nums_N >> can_K;

    for (int i = 1; i <= nums_N; i++)
        cin >> arr[i][0] >> arr[i][1];
    
    for (int i = 1; i <= can_K; i++){
        int temp_w, temp_v, remain_w = i;
        
        for (int j = 1; j <= nums_N; j++){
            // 남은 공간을 따로 저장해서 배열의 범위를 초과하는 일이 없도록 예외처리
            temp_w = arr[j][0];
            temp_v = arr[j][1];
            // 넣을 수 있으면
            if (temp_w <= i){
                dp[i][j] = max(dp[i][j-1], dp[i-temp_w][j-1] + temp_v);
                remain_w -= temp_w;
            }
            else{
                dp[i][j] = dp[i][j-1];
            }
            
            
            // 만약 넣게되면 남은 공간을 
        }
    
    }
    
    ans = dp[can_K][nums_N];



    cout << ans << '\n';
    return 0;
}