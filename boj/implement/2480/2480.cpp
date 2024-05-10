#include <iostream>
using namespace std;

void fast_io(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return;
}
int main(){

    fast_io();

    int a,b,c, reward;
    cin >> a >> b >> c;

// case 1: 3 same value > 10,000 + value*100
    if (a == b && b == c){
        reward = 10000 + a*1000;
    }
    else if (a == b || b == c || c ==a){// case 2: 2 same value > 1,000 + value*100
        if(a == b)
            reward = 1000 + a*100;
        else
            reward = 1000 + c*100;
    }
    else{// case 3 : no same value  > max_value*100
        reward = max(a,max(b,c))*100;
    }

    cout << reward << '\n';
    return 0;
}