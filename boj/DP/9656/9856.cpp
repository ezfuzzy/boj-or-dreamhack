#include <iostream>
#include <string>
using namespace std;

void fastIo(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}


int nums_N, ch;
string winner;
int main(){

    fastIo();
    cin >> nums_N;

    // 1 or 3
    ch = (nums_N-1) % 4;

    switch (ch)
    {
    case 0:
    case 2:
        winner = "CY";
        break; 
    case 1:
    case 3:
        winner = "SK";
        break;
    default:
        break;
    }

    cout << winner << '\n';
    return 0;
}