#include <iostream>
using namespace std;
#define fastIo ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;
char arr[101][101];


int main(){

    fastIo;

    cin >> n; // 1 ~ 100 dp? 
    
    string str;
    for (int i = 0; i < n; i++){
        cin  >> str;
        for (int j = 0; j < n; j++){    
            arr[i][j] = str[j];
        }
    }
    





    return 1;
}