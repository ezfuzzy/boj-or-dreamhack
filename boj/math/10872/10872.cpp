#include <iostream>
using namespace std;

long long fac(int n){
    if(n<=1)
        return 1;
    return n*fac(n-1);
}

int main(){
    
    int num;
    cin >> num;
    
    cout << fac(num) << endl;

    return 0;
}