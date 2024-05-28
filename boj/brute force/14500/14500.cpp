#include <bits/stdc++.h>
using namespace std;

int n, m, ans=0;// [4, 500]
int arr[500][500];

void find(int x, int y){

  if (y + 3 < m) ans = max(ans, arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x][y+3]);
  if (y + 2 < m && x + 1 < n){
    ans = max(ans, arr[x][y] + arr[x][y+1] + arr[x+1][y] + arr[x+1][y+1]);

    ans = max(ans, arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x+1][y+2]);
    ans = max(ans, arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x+1][y]);
    ans = max(ans, arr[x][y] + arr[x+1][y] + arr[x+1][y+1] + arr[x+1][y+2]);
    ans = max(ans, arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x+1][y+1]);
    ans = max(ans, arr[x][y] + arr[x][y+1] + arr[x+1][y+1] + arr[x+1][y+2]);
  }
  if (x + 2 < n && y + 1 < m){
    ans = max(ans, arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x+2][y+1]);
    ans = max(ans, arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x][y+1]);
    ans = max(ans, arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x+1][y+1]);
    ans = max(ans, arr[x][y] + arr[x][y+1] + arr[x+1][y+1] + arr[x+2][y+1]);
    ans = max(ans, arr[x][y] + arr[x+1][y] + arr[x+1][y+1] + arr[x+2][y+1]);
  }
  if (x + 2 < n && y - 1 >= 0){
    ans = max(ans, arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x+2][y-1]);
    ans = max(ans, arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x+1][y-1]);
    ans = max(ans, arr[x][y] + arr[x+1][y] + arr[x+1][y-1] + arr[x+2][y-1]);
  }
  if(x - 1 >= 0 && y + 2 < m){
    ans = max(ans, arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x-1][y+2]);
    ans = max(ans, arr[x][y] + arr[x][y+1] + arr[x-1][y+1] + arr[x-1][y+2]);
    ans = max(ans, arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x-1][y+1] );
  }
  if (x + 3 < n) ans = max(ans, arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x+3][y]);
}

int main(){
  cin >> n >> m;

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      find(i,j);
    }
  }
  
  cout << ans;
  return 0;
}