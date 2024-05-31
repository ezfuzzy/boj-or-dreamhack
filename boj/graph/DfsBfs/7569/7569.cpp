#include <bits/stdc++.h>
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

struct tomato{
  int x, y, z;
};

int m, n, h;
int boxes[100][100][100];
queue<tomato> bfsQ;

int bfs(){
  int cnt=0;

  while(!bfsQ.empty()){
    int _x = bfsQ.front().x;
    int _y = bfsQ.front().y;
    int _z = bfsQ.front().z;
    bfsQ.pop();

    int dx[6] = {0, 0, 0, 0, 1, -1};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {1, -1, 0, 0, 0, 0};
    
    for (int i = 0; i < 6; i++){
      if(_x+dx[i] >= 0 && _x+dx[i] < n && _y+dy[i] >= 0 && _y+dy[i] < m && _z+dz[i] >= 0 && _z+dz[i] < h){
        if(boxes[_x+dx[i]][_y+dy[i]][_z+dz[i]] == 0){
          tomato curTomato = {_x+dx[i], _y+dy[i], _z+dz[i]};
          bfsQ.push(curTomato);
          boxes[_x+dx[i]][_y+dy[i]][_z+dz[i]] = boxes[_x][_y][_z]+1;
          cnt = max(cnt, boxes[_x+dx[i]][_y+dy[i]][_z+dz[i]]);
        }
      }
    }
  }
  return cnt;
}

int main(){
  fastIo;
  cin >> m >> n >> h;

  bool isAllRippen = true;

  for (int a = 0; a < h; a++)
    for (int b = 0; b < n; b++)
      for (int c = 0; c < m; c++){
        cin >> boxes[b][c][a];
        if(boxes[b][c][a] == 1){
          tomato curTomato = {b,c,a};
          bfsQ.push(curTomato);
        }
        else if ( boxes[b][c][a] == 0)
          isAllRippen = false;
      }

  if(isAllRippen){
    cout << 0;
    return 0;
  }
  
  int ans = bfs();
  
  for (int a = 0; a < h; a++)
    for (int b = 0; b < n; b++)
      for (int c = 0; c < m; c++)
        if(boxes[b][c][a] == 0){
          cout << -1;
          return 0;
        }

  cout << ans-1;
  return 0;
}