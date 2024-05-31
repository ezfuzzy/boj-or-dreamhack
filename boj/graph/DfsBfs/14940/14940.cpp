#include <iostream>
#include <queue>

using namespace std;

int n, m; // 2 <= n, m <= 1000
int target_x, target_y;
int map[1001][1001];
queue<pair<int, int>> bfs_q;

void bfs() {

  bfs_q.push(make_pair(target_x, target_y));

  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {-1, 1, 0, 0};

  while(!bfs_q.empty()){
    int _x = bfs_q.front().first;
    int _y = bfs_q.front().second;
    bfs_q.pop();

    for (int i = 0; i < 4; i++){
      if(_x+dx[i] >= 0 && _y+dy[i] >= 0 && _x+dx[i] < n && _y+dy[i] < m && map[_x+dx[i]][_y+dy[i]] == 1){
        map[_x+dx[i]][_y+dy[i]] = map[_x][_y] + 1;
        bfs_q.push(make_pair(_x+dx[i], _y+dy[i]));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> map[i][j];
      if(map[i][j] == 2)
        target_x = i, target_y = j;
    }
  }

  bfs();

  // 원래 갈 수 없는 땅인 위치는 0을 출력하고, 
  // 원래 갈 수 있는 땅인 부분 중에서 도달할 수 없는 위치는 -1을 출력한다.
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if(map[i][j] == 1)
        map[i][j] = -1;
      else if (map[i][j] != 0)
        map[i][j] -= 2;
      cout << map[i][j] << " ";
    }
    cout << '\n';
  }

  return 0;   
}