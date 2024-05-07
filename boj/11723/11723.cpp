#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void fastIo(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
int nums_N, cur_num, S[21]={};
string cur_command;
int main(){

  fastIo();
  cin >> nums_N; // <= 3,000,000

  for (int i = 0; i < nums_N; i++){
    cin >> cur_command;

    if (cur_command == "add"){
      cin >> cur_num;
      S[cur_num] = cur_num;
    }
    else if (cur_command == "remove"){
      cin >> cur_num;
      S[cur_num] = 0;
    }
    else if (cur_command == "check"){
      cin >> cur_num;
      if(S[cur_num])
        cout << "1\n";
      else
        cout << "0\n";
    }
    else if (cur_command == "toggle"){
      cin >> cur_num;
      if (S[cur_num])
        S[cur_num] = 0;
      else
        S[cur_num] = cur_num;
    }      
    else if (cur_command == "all"){
      for (int i = 1; i <= 20; i++)
        S[i] = i;
    }
    else if (cur_command == "empty"){
      for (int i = 1; i <= 20; i++)
        S[i] = 0;
    }
  }
  return 0;
}