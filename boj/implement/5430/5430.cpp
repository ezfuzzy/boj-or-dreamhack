#include <bits/stdc++.h>
using namespace std;

int t, n;
string p, arr_str;

int main(){

  cin >> t;
  
  for (int T_cycle = 0; T_cycle < t; T_cycle++){ //  <= 100 
    vector<int> arr;
    cin >> p >> n >> arr_str;

    int cur_idx=0, isValid=0;
    string temp_str="";
    while(cur_idx < arr_str.size()){ // <= 101,000
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

    int start_idx = 0, end_idx = arr.size();
    bool isReverse = false, isError = false;
    int cycle = p.size();
    for (int k = 0; k < cycle; k++){ // 100,000
      switch (p[k])
      {
      case 'R':
        isReverse = !isReverse;
        break;
      case 'D':
        if(start_idx >= end_idx){
          isError = true;
          break;
        }
        else {
          if(isReverse)
            end_idx--;
          else
            start_idx++;
          break;
        }
      }
    }
    if(isError){
      cout << "error" << '\n';
      continue;
    }
    else if (!isError && start_idx == end_idx){
      cout << "[]" << '\n';
      continue;
    }

    if(!isReverse) {
      for (int i = start_idx; i < end_idx; i++){
        if(i == start_idx)
          cout << "[";

        if(i == end_idx-1)
          cout << arr[i] << "]" << '\n';
        else
          cout << arr[i] << ",";
      }
    }
    else{
      for (int i = end_idx-1; i >= start_idx ; i--){
        if (i == end_idx-1)
          cout << "[";

        if(i == start_idx)
          cout << arr[i] << "]" << '\n';
        else 
          cout << arr[i] << ",";
      }
    }

  } // end of T_cycle
    
  return 0;
}