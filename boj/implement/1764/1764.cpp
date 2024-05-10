#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void fastIo(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

int nums_N, nums_M, ans_arr[500000]; // <= 500,000
string arr[500000], temp_str;

int main(){

  fastIo();
  cin >> nums_N >>nums_M;

  for (int i = 0; i < nums_N; i++)
    cin >> arr[i];

  sort(arr, arr+nums_N);
  int idx= 0;
  for (int i = 0; i < nums_M; i++){ //bin search
    cin >> temp_str;
    int left=0, right=nums_N-1;
    while(left <= right){

      int mid = (left+right)/2;

      if (arr[mid] > temp_str){
        right = mid-1;
      }
      else if (arr[mid] < temp_str){
        left = mid+1;
      }
      else {
        ans_arr[idx] = mid;
        idx++;
        break;
      }
    }
  }
  sort(ans_arr, ans_arr + idx);
  cout << idx << '\n';
  for (int i = 0; i < idx; i++)
    cout << arr[ans_arr[i]] << '\n';
  

  return 0;
}