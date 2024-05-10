#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;


int main() {

    string ciphered_string = "PBESEMTDAPYQ";
    
    //cin >> ciphered_string;
   
   for (int i = 1; i < 10; i++)
   {
        for (char &c : ciphered_string) {
            c -= i;
        }
        cout << "---------------\n";
        cout << i << " : " << ciphered_string << '\n';
   }
   
    


    return 0;
}