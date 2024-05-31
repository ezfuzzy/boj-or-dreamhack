#include <bits/stdc++.h>
using namespace std;

int n, m;
queue<pair<int, int>> bfsQ;
int dist_map[101][101];

int bfs(){

  bfsQ.push(make_pair(0,0));

  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {-1, 1, 0, 0};
  int _x, _y;

  while(!bfsQ.empty()){
    _x = bfsQ.front().first;
    _y = bfsQ.front().second;
    bfsQ.pop();

    for (int i = 0; i < 4; i++){
      if(_x+dx[i] >= 0 && _y+dy[i] >= 0 && _x+dx[i] < n && _y+dy[i] < m){
        if(dist_map[_x+dx[i]][_y+dy[i]] != 0 && dist_map[_x+dx[i]][_y+dy[i]] == 1 && _x+dx[i]+_y+dy[i] != 0){
          bfsQ.push(make_pair(_x+dx[i], _y+dy[i]));
          dist_map[_x+dx[i]][_y+dy[i]] = dist_map[_x][_y] + 1;
        }
      }
    }
  }
  return dist_map[n-1][m-1];
}

int main() {

  cin >> n >> m;
  string str;
  for (int i = 0; i < n; i++){
    cin >> str;
    for (int j = 0; j < m; j++){
      dist_map[i][j] = str[j] - '0';
    }
  }

  cout << bfs();
  return 0; 
}