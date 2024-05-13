#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

void fastIo(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

int nums_N, nums_M; // 1 <= N,M <= 100,000
string temp_str;
map<string, int> dogam;
vector<string> sub;

bool isDigit(string str1){
  for(char ch1 : str1){
    if(!isdigit(ch1))
      return false;
  }
  return true;
}

int main(){
  fastIo();
  cin >> nums_N >> nums_M;

  for (int i = 1; i <= nums_N; i++){
    cin >> temp_str;
    dogam.insert(make_pair(temp_str, i));
    sub.push_back(temp_str);
  }

  for (int i = 0; i < nums_M; i++){
    cin >> temp_str;
    if(isDigit(temp_str)){
      cout << sub[stoi(temp_str)-1] << '\n';
    }
    else{ // input is string 
      cout << dogam[temp_str] << '\n';
    }
  }

  return 0;
}