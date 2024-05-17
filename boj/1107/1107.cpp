#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, ans=0;
// 0 <= n <= 500,000 , 0 <= m <= 10
int Button[10];
vector<int> target;
void find(int targetChannel){

  // btn[] == 0 : Active
  // btn[] == 1 : Broken
  int downsideChannel=0, uppersideChannel=0, tempChannel=0;

  int downBtn=0, upperBtn=9, vaildCheck=0;
  for (int i = 0; i < 10; i++){
    if(Button[i] == 0){
      downBtn = max(downBtn, i);
      upperBtn = min(upperBtn, i);
      vaildCheck = 1;
    }
  }
  if (!vaildCheck){
    ans = -1;
    return;
  }
  
  bool isBroken = false;
  for (int i = 0; i < target.size(); i++){
    if(!isBroken){
      if(Button[target[i]] == 0){ // click btn 
        tempChannel += target[i] * pow(10, target.size()-(i+1));
      }
      else {
        isBroken = true;
        // set first num of sidesChannel
        int forDown=0, forUpper=9;
        for (int j = 0; j < 10; j++){
        // target[i] 보다 작은 수중 제일 큰 수
          if(Button[j] == 0 && j < target[i]){
            forDown = max(forDown, j);
          }
        // target[i] 보다 큰 수중 제일 작은 수
          if(Button[j] == 0 && j > target[i]){
            forUpper = min(forUpper, j);
          }
        }
        // if 작은 순데 앞자리가 같고 다음 자리가 0일떄  ?? !! > 9가 1이면 이게 안되니까 이것도 체크해줘야함
        // error case 00 : 500000 8 0 2 3 4 6 7 8 9 > 455555 : 155555
        // 첫번째 자리에서 걸릴 경우에 tempChannel == 0
        // 최솟값 설정이 제대로 안됨.
        int weight=0;
        if(Button[0] == 1 && forDown == 0 && tempChannel != 0){
          for (int cnt = 1; cnt < 10; cnt++)
          {
            int temp_digit = ((tempChannel - cnt*pow(10,target.size()-i)) / pow(10, target.size()-i));
            temp_digit %= 10;

            if(Button[temp_digit])
              continue;
            else {
              weight = cnt;
              break;
            }
          }
          downsideChannel = tempChannel - weight*pow(10,target.size()-i) + downBtn * pow(10, target.size()-(i+1));
        } // 첫번쨰 자리가 1 또는 0 일때 에러 고쳐야함 
        else if (tempChannel == 0) { // > 이렇게 처리하니까 0 2 0 1 에서 0으로 인식해서 바로 0 갈겨버림
          continue;
        }
        else
          downsideChannel = tempChannel + forDown * pow(10, target.size()-(i+1));

        // if 큰순데 --- !! error case 00 : 599 2 6 9 > 600 : 700
        if(Button[9] == 1 && forUpper == 9){
          for (int cnt = 1; cnt < 10; cnt++)
          {
            int temp_digit = ((tempChannel + cnt*pow(10,target.size()-i)) / pow(10, target.size()-i));
            temp_digit %= 10;

            if(Button[temp_digit])
              continue;
            else {
              weight = cnt;
              break;
            }
          }
          uppersideChannel = tempChannel + weight*pow(10, target.size()-i) + upperBtn * pow(10, target.size()-(i+1));
        } // 9xx인데 9가 고장났을떄 자릿수 + 1을 해야함 (이떄도 안고장난지 체크하면서 해야함)
        else
          uppersideChannel = tempChannel + forUpper * pow(10, target.size()-(i+1));
      }
    }
    else {  // broken : find adjacent number in active btn
      downsideChannel += downBtn * pow(10, target.size()-(i+1));
      uppersideChannel += upperBtn * pow(10, target.size()-(i+1));
    }
    cout << "[down] : " << downsideChannel << " [up] : " << uppersideChannel << " [temp] : " << tempChannel << '\n';
    ans++;
  }


// https://www.acmicpc.net/board/view/134925 : 반례 모음
// 1
// 9
// 1 2 3 4 5 6 7 8 9 여기까지했고 이것도 오류

  if(isBroken)
    ans += min(abs(targetChannel - downsideChannel), abs(targetChannel - uppersideChannel));
  else
    ans += abs(targetChannel - tempChannel);
}
int main(){

  cin >> n >> m;

  // num btn만 고장. 
  for (int i = 0; i < m; i++){
    int temp;
    cin >> temp; 
    Button[temp] = 1;
  }

  int temp_target = n, cur_num;
  while(temp_target > 0){
    cur_num = temp_target % 10;
    temp_target /= 10;
    target.push_back(cur_num);
  }
  reverse(target.begin(), target.end());

/*
  cur_channel = 100;

  exception 0: target chnnel == 100
  1. 조합할 수 있는 숫자중 가장 가까운 숫자 입력 << key algorithm
  check abs ? 
  > 첫번쨰 자리부터 비교해서 최대한 같은 숫자 넣어야함

  exception 1-1: +, -로 이동하는게 더 빠를 때 
  exception 1-2: 가장 가까운 큰 숫자 or 가장 가까운 작은 숫자
  
  2. +, -  이동*/

  
  find(n);
  ans == -1 ? ans = abs(n-100) : ans = min(ans, abs(n-100));
  cout << ans;
  return 0;
}