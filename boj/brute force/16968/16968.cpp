#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string base;
int ans = 1;
int main(){
  cin >> base;

  for (int i = 0; i < base.size(); i++){
    if(base[i] == 'c'){ // c = 26
      if(!i || base[i-1] == 'd')
        ans*=26;
      else
        ans*=25;

    }
    else { // d = 10
      if(!i || base[i-1] == 'c')
        ans*=10;
      else
        ans*=9;
      
    }
  }
  cout << ans << '\n';
  return 0;
}