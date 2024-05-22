#include <bits/stdc++.h>
using namespace std;

int T, n; // T <= 100, 0 <= n <= 30
map<string, int> clothes;

int main(){
  cin >> T;

  while(T--){

    cin >> n;
    string item, type;
    int NoT = 0;
    for (int i = 0; i < n; i++){
      
      cin >> item >> type;

      if(clothes.count(type) == 0){
        clothes[type] = 1;
        NoT++;
      }
      else
        clothes[type]++;
    }

    //process 
    for (int i = 1; i <= NoT; i++){
      // 옷 종류의 수 만큼 ... 
       // > vector로 이관 후 계산 ?  

    }
    

    

  }

  return 0;
}