#include <bits/stdc++.h>
using namespace std;

int a, b; // [1, 10^9]
int ans=0; // min(a -> b)

queue<pair<int, int>> bfsQ;

void bfs(){
  bfsQ.push({a, 1});
  
  while(!bfsQ.empty()){

    int curNum = bfsQ.front().first;
    int curCnt = bfsQ.front().second;
    bfsQ.pop();

    if(curNum == b){
      ans = curCnt;
      return;
    }
    
    if(curNum <= 500000000)
      bfsQ.push({curNum*2, curCnt+1});
    if(curNum <= 99999999)
      bfsQ.push({curNum*10 + 1, curCnt+1});
    
  }
  ans = -1;
}

int main(){ 
  cin >> a >> b;

  bfs();
  cout << ans;
  return 0;
}