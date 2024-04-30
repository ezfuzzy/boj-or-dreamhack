#include <iostream>
#include <string>
using namespace std;

void fastIo(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}


int nums_N, ch_remainder;
bool is_quotient_odd;
string winner;
int main(){

    fastIo();
    cin >> nums_N;

    ch_remainder = nums_N % 4;
    is_quotient_odd = (nums_N / 4) % 2;  // if odd ? 1(true) : 0(false)
    
    switch (ch_remainder)
    {
    case 0:
    case 2:
        if (is_quotient_odd)
            winner = "CY";
        else
            winner = "SK";
        break; 
    case 1:
    case 3:
        if (nums_N <=10)
            winner = "SK";
        else{
            if (is_quotient_odd)
                winner = "CY";
            else
                winner = "SK";
        }
        break;
    default:
        break;
    }


    std::cout << winner << '\n';
    return 0;
}