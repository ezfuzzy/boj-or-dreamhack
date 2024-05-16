#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int n, k, temp_num, ans; // 0 <= n, k <= 100000
queue<int> bfs_q;
int ans_sheet[100001];
bool isChecked[100001];
const int MAX = 100000;

void bfs(int _n){
  bfs_q.push(_n);
  
  while(!bfs_q.empty()){
    temp_num = bfs_q.front();
    bfs_q.pop();
    if(temp_num < 0 || temp_num > 100000 || isChecked[temp_num]) continue;
    isChecked[temp_num] = true;
    if(temp_num == k) return;
    
    //case 1: walking > _n-1    
    if(!isChecked[temp_num-1]){
      bfs_q.push(temp_num-1);
      if(!ans_sheet[temp_num-1])  ans_sheet[temp_num-1] = ans_sheet[temp_num]+1;
    }
    //case 2: walking > _n+1
    if(!isChecked[temp_num+1]){
      bfs_q.push(temp_num+1);
      if(!ans_sheet[temp_num+1]) ans_sheet[temp_num+1] = ans_sheet[temp_num]+1;
    }
    //case 3: teleporting > 2*_n
    if(temp_num <= MAX/2 && !isChecked[temp_num*2]){
      bfs_q.push(temp_num*2);
      if(!ans_sheet[temp_num*2]) ans_sheet[temp_num*2] = ans_sheet[temp_num]+1;
    } 
    
  }
}

int main(){
  cin >> n >> k;
  
  bfs(n);
  
  if(n == k) ans = 0;
  else ans = ans_sheet[k];
  
  cout << ans << '\n';
  return 0;
}