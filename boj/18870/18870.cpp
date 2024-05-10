#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fastIo(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

int nums_N, temp_num; // <= 1,000,000
vector<int> arr;
int main(){
  cin >> nums_N;

  for (int i = 0; i < nums_N; i++){
    cin >> temp_num;
    arr.push_back(temp_num);
  }

  sort(arr.begin(), arr.end());

  for (int i = 0; i < nums_N; i++){
    
    



  }
  


  return 0;
}