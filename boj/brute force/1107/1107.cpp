#include <iostream>
#include <string>

using namespace std;

int broken[10] = {0,};
int n, m;
string target_str;

bool check_ch(int target){
  target_str = to_string(target);
  for (int i = 0; i < target_str.size(); i++){
    if(broken[target_str[i] - '0']) // > check that btn is broken. 
      return false;
  }
  return true;
}

int main(){

  cin >> n >> m;

  for (int i = 0; i < m; i++){
    int btn_num;
    cin >> btn_num;
    broken[btn_num] = 1;
  }
  
  int ans = abs(n - 100); // only use +, - btn 

  for (int i = 0; i <= 10e6; i++){ // brute force
    if(check_ch(i)){
      int temp_ans = abs(n - i) + target_str.size();
      ans = min(ans, temp_ans);
    }
  }
  
  cout << ans;
  return 0;
}