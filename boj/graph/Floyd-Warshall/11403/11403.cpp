#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int adj[101][101], dist[101][101], n;

void init(){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (adj[i][j]) dist[i][j] = 1;
      else dist[i][j] = INF; 
    }
  }
}

void solve(){
  for (int k = 0; k < n; k++){
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if(dist[i][j] == INF) cout << 0 << ' ';
      else cout << 1 << ' ';
    }
    cout << '\n';
  }
}

int main(){

  cin >> n;

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> adj[i][j];
    }
  }

  init();
  solve();

  return 0;
}