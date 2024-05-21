#include <bits/stdc++.h>
using namespace std;

int T, m, n, x, y;


int main(){
  cin >> T;

  for (int cycle_T = 0; cycle_T < T; cycle_T++){
    
    cin >> m >> n >> x >> y;

    vector<int> dx;
    int ans=-1;

    for (int i = 0; i <= n; i++){
      dx.push_back(i*m+x);
    }

    for (int i = 0; i < dx.size(); i++){
      int curY = dx[i]%n;
      if(curY == 0) curY = n;

      if(curY == y){
        ans = dx[i];
        break;
      }
    }
   
    cout << ans << '\n';
  } // end of for T 
  return 0;
}