#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main() {
  ll a, b, c;

  cin >> a >> b >> c;
  
  ll ans = 1; // 곱셈의 항등원

  a %= c; // 미리 모듈러 연산을 해줌으로써 overflow 방지 (결과 안변함)
    
/* 
 * key: 지수를 반으로 줄이며 최소화.
 * 모듈러 연산을 중간에 해줘도 모듈러 연산의 결과는 변하지 않음(overflow 방지)
 * 홀수일 경우 짝수로 맞춰주기 위해 a를 곱해서 처리
 */
    
  while(b>0){ 
    if(b%2 == 1){              // 홀수일 경우: a를 곱해서 ans에 저장 후 모듈러 
      ans = (ans * a) % c;     // > a*a^(b-1) % c :: b-1은 짝수
    }                          // 따라서 b >> 1을 논리적으로 수행가능 
    b = b >> 1;                // b는 정수이기때문에 굳이 1을 빼주지 않아도 >> 연산을 통해 나머지(소수점)는 버려짐
    a = (a * a) % c;           // (a^2)^b/2 % c 에서 a^2을 처리하는 과정 
  }                            // == > 따라서 이 후에 식이 a^b/2 % c로 간소화된다.
    
  // > b를 2로 나눠가몀 진행하기 때문에 원래 시간복잡도인 
  // > O(b)에서 O(logb)로 줄어듬

  cout << ans;
  return 0;
}