#include <bits/stdc++.h>
using namespace std;
#define fastIo std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int n, m; // [1, 8]
vector<string> ans;

int main(){
  fastIo;

  cin >> n >> m;

  int bitMask = (1 << n) -1; // n자리의 비트마스크 : 1이 n개 있음 
  //  ex> n == 3: bitMask == 111(2) == 7(10)
  bool isFirst = true;

  for (int i = 1; i <= bitMask; i++){
    
    //initialize
    int cnt = 0;
    string str = "";

    /* n = 3을 기준으로 
     * i는 001 ~ 111 을 방문 
     * for(j)문에서 j는 각 비트 자리의 인덱스
     * ex> i가 101 일떄 j == 0, 2에서 if문이 통과
     */
    for (int j = 0; j < n; j++){
      if(i & (1 << j)){ // 해당 인덱스가 이번 i에 대한 순열에 포함되는지 체크
        
        str += to_string(j+1) + " "; // 추가
        cnt++; // m판단을 위한 cnt
      }
    }
    if(cnt == m){  // m개를 고른 수열
      ans.push_back(str);
    }
  }
  
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i] << '\n';
  }
  
  return 0;
}