#include <bits/stdc++.h>
using namespace std;

int n, m;

map<int, int> shortcut;
queue<int> bfsQ;
bool isVisited[101];
int board[101];

//init board, ladder, snake
void init(){
  int x, y;
 for (int i = 2; i < 101; i++) // start at 1 / max value is 17
    board[i] = 20;

  for (int i = 0; i < n + m; i++){
    cin >> x >> y;
    shortcut.insert({x, y});
  }
}

// solve using bfs
void bfs(){
  int x = 1;
  bfsQ.push(x);
  isVisited[x] = true;

  while(!bfsQ.empty()){
    x = bfsQ.front();
    bfsQ.pop();
    
    for (int i = 1; i <= 6; i++){  
      if(x+i > 100) break;
      if(!isVisited[x+i]){
        board[x+i] = min(board[x+i], board[x] + 1);
        isVisited[x+i] = true;

        if(shortcut.count(x+i) == 0){
          bfsQ.push(x+i);
        }
        else { // check if there is a shortcut
          int nx = shortcut[x+i];
          if(x+i < nx) bfsQ.push(x+i);
          
          board[nx] = min(board[nx], board[x+i]);
          bfsQ.push(nx);
          isVisited[nx] = true;
        }
      }
    }
  }
}

int main(){

  cin >> n >> m; // 1 <= n, m <= 15

  init();
  bfs();

  cout << board[100];
  return 0;
}