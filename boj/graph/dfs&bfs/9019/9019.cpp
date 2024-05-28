#include <bits/stdc++.h>
using namespace std;

int T;
int a, b; // a : first value, b: target value
                          //0 <= a,b < 10,000
queue<pair<int, string>> bfsQ;
bool visited[10000];


void check(int num, string cmd){
  if(!visited[num]){
    bfsQ.push({num, cmd});
    visited[num] = true;
  }
}

string bfs(){
  while(!bfsQ.empty()) bfsQ.pop();
  fill(begin(visited), end(visited), false);

  bfsQ.push({a, ""});
  visited[a] = true;

  while(!bfsQ.empty()){
    int curNum = bfsQ.front().first;
    string curCmd = bfsQ.front().second;
    bfsQ.pop();

    if(curNum == b) return curCmd + "\n";

    // case 1: D
    int case_1_curNum = (curNum * 2) % 10000;
    check(case_1_curNum, curCmd+"D");

    // case 2: S
    int case_2_curNum = curNum - 1;
    if(case_2_curNum < 0) case_2_curNum = 9999;
    check(case_2_curNum, curCmd+"S");

    // case 3: L
    int case_3_curNum = (curNum % 1000) * 10 + curNum / 1000;
    check(case_3_curNum, curCmd+"L");

    // case 4: R
    int case_4_curNum = (curNum % 10) * 1000 + curNum / 10;    
    check(case_4_curNum, curCmd+"R");
  }
  return "";
}

int main(){

  cin >> T;

  while(T--){
    cin >> a >> b;
    cout << bfs();
  }

  return 0;
}
