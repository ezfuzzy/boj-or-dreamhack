#include <iostream>
using namespace std;


void fastIo(){
    ios::sync_with_stdio(0);
    cin.tie(0);
}
int nums_N;
char arr[101][101];
int main(){

    fastIo();

    cin >> nums_N; // 1 ~ 100 dp? 

    for (int i = 0; i < nums_N; i++){
        for (int j = 0; j < nums_N; j++){    
            cin >> arr[i][j];
        }
    }
    





    return 1;
}