#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int b_n, temp_n, ans_n=0;
string a, b, temp_a, temp_str="", ans="";
bool visited[10];

void dfs(char _a){
  
  temp_str += _a;
  if (temp_str.size() == a.size()){
    std::istringstream iss_temp(temp_str);
    
    iss_temp >> temp_n;
    if (temp_n < b_n){
      if (temp_n > ans_n){
        ans = temp_str;
        ans_n = temp_n;
      }
    }
    return;
  }
  
  for (int i = 0; i < a.size(); i++){
    if (visited[i]) continue;
    visited[i] = true;
    dfs(a[i]);
    visited[i] = false;
    temp_str.pop_back();
  }
}


int main(){

  cin >> a >> b;

  std::istringstream iss_b(b);
  iss_b >> b_n;

  sort(a.begin(), a.end(), greater<int>());

  for (int i = 0; i < a.size(); i++){
    if (a[i] == '0') continue;
    visited[i] = true;
    dfs(a[i]);
    visited[i] = false;
    temp_str.pop_back();
  }

  std::istringstream iss_ans(ans);
  iss_ans >> ans_n;
  
  (ans_n > b_n || ans == "") ? cout << -1 << '\n' : cout << ans << '\n';
  
  return 0;
}