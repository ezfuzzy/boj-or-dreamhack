#include <bits/stdc++.h>
using namespace std;

int t, n;
string p, arr_str;

int main(){

  cin >> t;
  
  for (int i = 0; i < t; i++){ // max 100 
    vector<int> arr;
    cin >> p >> n >> arr_str;

    int cur_idx=0, isValid=0;
    string temp_str="";
    while(cur_idx < arr_str.size()){ // 100,000
      if(arr_str[cur_idx] ==  '[') {}
      else if (arr_str[cur_idx] == ',' || arr_str[cur_idx] == ']'){
        int arr_num=0;
        for (int arr_idx = 0; arr_idx < temp_str.size(); arr_idx++){ // part of 100,000 여기서도 시간초과 나는거같은데
          arr_num += (temp_str[arr_idx]-'0') * pow(10, temp_str.size()-(arr_idx+1));
        }
        if(isValid)
          arr.push_back(arr_num);
        temp_str = "";
      }
      else {
        temp_str += arr_str[cur_idx];
        isValid = 1;
      }

      cur_idx++;
    }

    int cycle = p.size();
    for (int k = 0; k < cycle; k++){ // 100,000
      switch (p[k])
      {
      case 'R':
        reverse(arr.begin(), arr.end()); 
        break;
      case 'D':
        if(arr.size() == 0){
          cout << "error" << '\n';
          break;
        }
        else {
          arr.erase(arr.begin()); // 100,000
          break;
        }
      }
    }
    
    for (int i = 0; i < arr.size(); i++){
      if(i==0)
        cout << "[" << arr[i] << ",";
      else if(i == arr.size()-1)
        cout << arr[i] << "]" << '\n';
      else
        cout << arr[i] << ",";
    }
  }
    
  return 0;
}