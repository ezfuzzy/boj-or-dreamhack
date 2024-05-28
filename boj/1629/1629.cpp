#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main() {
  int a, b, c;

  cin >> a >> b >> c;
  
  ll ans = 1;

  a %= c; 

  while(b>0){
    if(b%2 == 1){
      ans = (ans * a) % c;
    }
    b = b >> 1;
    a = (a * a) % c;
  }

  cout << ans;
  return 0;
}