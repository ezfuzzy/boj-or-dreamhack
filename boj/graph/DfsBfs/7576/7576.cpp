#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n, m, ans=0; // 2 <= m, n <= 1000
int box[1001][1001];
queue<pair<int, int>> bfs_q;

void bfs(){ 
  
  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {-1, 1, 0, 0};

  while(!bfs_q.empty()){
    int row_idx = bfs_q.front().first;
    int col_idx = bfs_q.front().second;
    bfs_q.pop();
  
    // 1 : ripen, 0 : unripen, -1 : empty
    for (int i = 0; i < 4; i++){
      if(row_idx + dx[i] >= 0 && row_idx + dx[i] < n && col_idx + dy[i] >= 0 && col_idx + dy[i] < m){
        if (box[row_idx + dx[i]][col_idx + dy[i]] == 0){
          box[row_idx + dx[i]][col_idx + dy[i]] = box[row_idx][col_idx] + 1;
          bfs_q.push(make_pair(row_idx + dx[i], col_idx + dy[i]));
          ans = max(ans, box[row_idx+dx[i]][col_idx+dy[i]]);
        }
      }
    }
  }
}

int main(){
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> m >> n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> box[i][j];
      if(box[i][j] == 1) bfs_q.push(make_pair(i, j));
    }
  }
  
  bfs();

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if(box[i][j] == 0) {
        cout << -1;
        return 0;
      }
    }
  }
  if(ans == 0) cout << 0;
  else cout << ans-1;

  return 0; 
}