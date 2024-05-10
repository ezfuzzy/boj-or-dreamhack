#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fastIo(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

int nums_N, temp_num, arr[1000001];
vector<int> arr_zip;

int main(){
  fastIo();
  cin >> nums_N;

  for (int i = 0; i < nums_N; i++){
    cin >> arr[i];
    arr_zip.push_back(arr[i]);
  }
  sort(arr_zip.begin(), arr_zip.end());
  arr_zip.erase(unique(arr_zip.begin(), arr_zip.end()), arr_zip.end());
  
  for (int i = 0; i < nums_N; i++)
    cout << lower_bound(arr_zip.begin(), arr_zip.end(), arr[i])-arr_zip.begin() << " ";
  

  cout <<'\n';
  return 0;
}