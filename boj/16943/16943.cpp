#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int a, b; // <= pow(10,9)
char temp_ch='0', temp_node;
string temp_str="";

int main(){

  cin >> a >> b;

  string str_a = to_string(a);
  string str_b = to_string(b);
  
  if (str_a.size() == str_b.size()){
    
    for (int i = 0; i < str_b.size(); i++){
      if (str_a[i] <= str_b[0]){ //str_b의 첫번째 자릿수보다 작은 것중에 제일 큰 str_a의 자릿수
        temp_node = max(temp_node, str_a[i]);
      }

    }
    // process
    for (int j = 0; j < str_a.size(); j++){ // delete
      if (str_a[j] == temp_node){
        str_a.erase(j, 1);
        break;
      }
    }
    temp_str += temp_node;
    sort(str_a.begin(), str_a.end(), greater<char>());

    if (temp_node == '0'){ // case 1: 불능 - a의 모든 자릿수가 b의 첫번쨰 숫자보다 큼
      cout << -1 << '\n';
      return 0;      
    } // ====================================================//
    else if (temp_node == str_b[0]){ //case 2: 같음 - 뒤에 숫자들을 비교
      

      for (int i = 1; i < str_b.size(); i++){
        for (int j = 0; j < str_a.size(); j++){
          if (str_a[j] <= str_b[i]){ 
            temp_str += str_a[j];
            str_a.erase(j, 1);
          }
        }
      }
      if (temp_str == str_b)
        cout << -1 << '\n';
      
    } // ====================================================//
    else { //case 3: temp_node < str_b[0] : temp_node를 제외한 나머지 숫자들을 정렬
      
      cout << temp_str << str_a << '\n';
    }
  }
  else if (str_a.size() < str_b.size()){
    cout << str_a << '\n';
  }
  else{
    cout << -1 << '\n';
  }

  return 0;
}