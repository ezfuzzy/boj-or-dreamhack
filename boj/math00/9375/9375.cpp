#include <bits/stdc++.h>
using namespace std;

int T, n; // T <= 100, 0 <= n <= 30
map<string, int> clothes;

int main(){
  cin >> T;

  while(T--){
    //reset
    clothes.clear();

    cin >> n;
    string item, type;
    for (int i = 0; i < n; i++){
      
      cin >> item >> type;

      if(clothes.count(type) == 0){
        clothes[type] = 1;
      }
      else
        clothes[type]++;
    }

    int sum = 1;
    for (const auto& curItem: clothes){ // <= 30
      sum *= (curItem.second + 1);
    }
    /* 
    > 각 type의 갯수에 + 1을 해줌은 입는다/입지 않는다의 bit 연산을 추가해주는 것이다.
     */
    cout << sum - 1 << '\n'; // subtract 1: must wear at least one item
  }

  return 0;
}