#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, ans=0;
char c, campus[601][601];
queue<pair<int, int>> bfsQ;

void bfs(){
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  while(!bfsQ.empty()){
    x = bfsQ.front().first;
    y = bfsQ.front().second;
    bfsQ.pop();

    for (int i = 0; i < 4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];
      
      if(nx >= 0 && nx < n && ny >= 0 && ny < m){
        if(campus[nx][ny] == 'O'){
          bfsQ.push({nx, ny});
          campus[nx][ny] = 'I';
        }
        else if(campus[nx][ny] == 'P'){
          ans++;
          bfsQ.push({nx, ny});
          campus[nx][ny] = 'I';
        }
      }
    }
  }
}

int main(){

  cin >> n >> m;

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> campus[i][j];
      if(campus[i][j] == 'I')
        bfsQ.push({i, j});
    }
  }
  
  bfs();

  if(ans)
    cout << ans;
  else
    cout << "TT";

  return 0;
}