#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int nums_N, nums_M, temp_num, sum=0, ans=100000;

int main(){
  
  cin >> nums_M; // <= 10,000
  cin >> nums_N;

  for (int i = nums_M; i <= nums_N; i++){
    if (i - pow(int(sqrt(i)), 2))
      continue;
    else{
      ans = min(ans, i);
      sum += i;
    }
  }
  
  if(sum)
    cout << sum << '\n' << ans << '\n';
  else
    cout << -1 << '\n';


  return 0;
}