#include <bits/stdc++.h>
using namespace std;

int T, k;

int main(){

  cin >> T;
  char c;
  int inputNum;

  for (int cycle_T = 0; cycle_T < T; cycle_T++){
    
    cin >> k; // <= 1,000,000

    // I n : insert n to Q
    // D n : delete n from Q
    // D 1 : D max value 
    // D -1 : D min value
    // D to empty Q : ignore
  
    
    
    for (int i = 0; i < k; i++){
      cin >> c >> inputNum;
      switch (c)
      {
      case 'I':

        break;
      case 'D':

        break;
      default:
        break;
      }   
    }
    

  }
  
  //  ans : max " " min
  //  if Q is empty, print "EMPTY"
  return 0;
}