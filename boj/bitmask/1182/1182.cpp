#include <bits/stdc++.h>
using namespace std;

int n, s; //n = [1,20], s = [abs(1,000,000)]

int main(){
  cin >> n >> s;

  int arr[n];
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  
  int bitMask = (1<<n)-1;
  int ans = 0;

  for (int i = 1; i <= bitMask; i++){
    int sum = 0;
    for (int j = 0; j < n; j++){
      if(i & (1<<j)){
        sum += arr[j];
      }
    }
    if(sum == s) ans++;
  }
  
  cout << ans;
  return 0;
}