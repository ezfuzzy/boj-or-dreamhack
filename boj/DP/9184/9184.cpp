#include <iostream>
#include <cmath>
using namespace std;
int answer[21][21][21]; // 0 ~ 20 > 21 

int w(int _a, int _b, int _c){
    int temp_answer;

    if(min(min(_a, _b), _c) <= 0){
        answer[_a][_b][_c] = 1;
        return 1;
    }
    else if(max(max(_a,_b),_c) > 20)
        _a = 20, _b = 20, _c = 20;
        
    if(answer[_a][_b][_c])
        return answer[_a][_b][_c];

    if(_a < _b && _b < _c){
        temp_answer = w(_a, _b, _c-1) + w(_a, _b-1, _c-1) - w(_a, _b-1, _c);
        answer[_a][_b][_c] = temp_answer;
        return temp_answer;
    }
    else{
        temp_answer = w(_a-1, _b, _c) + w(_a-1, _b-1, _c) + w(_a-1, _b, _c-1) - w(_a-1, _b-1, _c-1);
        answer[_a][_b][_c] = temp_answer;
        return temp_answer;
    }
}
void output(int _a, int _b, int _c, int _answer){
    printf("w(%d, %d, %d) = %d\n", _a, _b, _c, _answer);
}

int main(){
    int a, b, c;
    while(1){
        scanf("%d %d %d", &a, &b, &c);
        
        if(a == -1 && b == -1 && c == -1)
            return 0;

        if(min(min(a, b), c) <= 0){
            output(a,b,c,1);
            continue;
        }
        
        output(a,b,c,w(a,b,c));
    }
    return 0;
}