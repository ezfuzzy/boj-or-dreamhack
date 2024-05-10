#include <iostream>
#include <string>
using namespace std;

void fastIo(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string s;
int temp, cycle;
int main(){
    
    fastIo();
    cin >> s;

    for (int i = 0; i < s.size(); i++){   
        temp = int(s[i]);
        cycle = 0;
        do{
            cycle += (temp%10);
        } while(temp/=10);

        for (int j = 0; j < cycle; j++){
            cout << s[i];    
        }
        cout << '\n';
    }
    
    
    return 0;
}