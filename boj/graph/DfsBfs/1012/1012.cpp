#include <iostream>
#include <vector>
using namespace std;

void fastIo(){
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int case_T, row_M, col_N, loc_K, ans=0; // 0 <= N, M <= 49 / K <= 2,500
bool visited[51][51];

void dfs(int temp_row, int temp_col){
  visited[temp_row][temp_col] = false;
  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {1, -1, 0, 0};
  for (int i = 0; i < 4; i++){
    int next_row = temp_row + dx[i];
    int next_col = temp_col + dy[i];
    if (next_row < 0 || next_row >= row_M || next_col < 0 || next_col >= col_N) continue;
    if (visited[next_row][next_col]){
      dfs(next_row, next_col);
    }
  }
  
}

int main() {

    fastIo();
    cin >> case_T;

    for (int i = 0; i < case_T; i++){
      
      cin >> row_M >> col_N >> loc_K;

      for (int i = 0; i < loc_K; i++){
        int x, y;
        cin >> x >> y;
        visited[x][y] = true;
      }
    
      for (int i = 0; i < row_M; i++){
        for (int j = 0; j < col_N; j++){
          if (visited[i][j]){
            dfs(i, j);
            ans++;
          }
        }
      }

      cout << ans << '\n';
      ans=0;
    }

    return 0;
}