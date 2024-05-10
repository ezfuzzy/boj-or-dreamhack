#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int temp_num, temp_minus=0, temp_result=0;
    string s, temp_str="";
    bool is_in_parenthesis = false;
    //scanf("%s", &s); > scanf를 사용할 때 문자열의 길이를 지정하지 않으면 오버플로우가 발생할 수 있어서 문자열의 길이를 조정해주는 것이 좋다. 
    cin >> s;

    for (int i = 0; i < s.length(); i++){

        if (s[i] == '+'){
            temp_num = stoi(temp_str);
            if(is_in_parenthesis)
                temp_minus += temp_num;
            else
                temp_result += temp_num;
            temp_str = "";
        }
        else if (s[i] == '-'){
            temp_num = stoi(temp_str);
            if (is_in_parenthesis){
                temp_minus += temp_num;
                temp_result -= temp_minus;
                temp_minus = 0;
            }
            else
                temp_result += temp_num;
            
            temp_str = "";
            is_in_parenthesis = true;
        }
        else
            temp_str += s[i];
    }

    temp_num = stoi(temp_str);
    if(is_in_parenthesis){
        temp_minus += temp_num;
        temp_result -= temp_minus;
    }
    else
        temp_result += temp_num;

    printf("%d\n", temp_result);
    return 0;
}