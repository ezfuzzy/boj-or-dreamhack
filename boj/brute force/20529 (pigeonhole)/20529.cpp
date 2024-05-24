#include <bits/stdc++.h>
using namespace std;

int T, n, ans=8;
// 1 <= T <= 50
// 3 <= n <= 100,000

/*  16개 유형으로 정해진 MBTI는
    최적으로 배치해도 33명부터는 3명 이상인 MBTI는 적어도 1개 이상 생길 수 밖에 없다.
    따라서 32명 이하만 처리해주면 된다.
    > 16 + 16 = 32 ... 
 */
int cmp(string a, string b){
  int cnt = 0;
  for (int i = 0; i < 4; i++)
    if(a[i] != b[i]) cnt++;
 
  return cnt;
}

int main(){

  cin >> T;

  while(T--){
    vector<string> mbti;
    ans = 200;

    cin >> n;
    for (int i = 0; i < n; i++){
      string inputMbti;
      cin >> inputMbti;
      mbti.push_back(inputMbti);
    }
        
    if(n > 32){
      cout << 0 << '\n';
      continue;
    }
    else{
      for (int k = 0; k < n-2; k++){
        for (int i = k+1; i < n-1; i++){
          for (int j = i+1; j < n; j++){
            ans = min(ans, cmp(mbti[k], mbti[i]) + cmp(mbti[i], mbti[j]) + cmp(mbti[j], mbti[k]));
          }
        }
      }
          
      cout << ans << '\n';
    }
  }

  return 0;
}