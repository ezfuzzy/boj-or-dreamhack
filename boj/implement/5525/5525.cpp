#include <bits/stdc++.h>
using namespace std;

int n, m, ans=0; // 1 <= n,m <= 1,000,000 
string s;

int main(){
  cin >> n >> m >> s;
  bool isSucceed = false;
  
  int nSize = 2*n+1;
  for (int i = 0; i < m; i++){
    if(s[i] == 'I'){
      int cnt = 0;
      while(s[i+1] == 'O' && s[i+2] == 'I'){
        i += 2;
        cnt++;
        if(cnt == n){
          ans++;
          cnt--;
        }
      }
    }
  }
  
  cout << ans;
  return 0;
}