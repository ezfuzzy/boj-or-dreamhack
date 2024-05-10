#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void fastIo(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

int nums_N, nums_M, start_V;
vector<int> graph[1001];
queue<int> bfs_q;
bool dfs_visited[1001], bfs_visited[1001];

void dfs(int n){
  cout << n << " ";
  dfs_visited[n] = true;
  for(int i : graph[n])
    if (!dfs_visited[i])
      dfs(i);
}

void bfs(int n){
  bfs_q.push(n);
  bfs_visited[n] = true;
  
  while(!bfs_q.empty()){
    n = bfs_q.front();
    bfs_q.pop();
    cout << n << " ";

    for (int i : graph[n]){
      if (!bfs_visited[i]){
        bfs_q.push(i);
        bfs_visited[i] = true;
      }
    }
  }
}

int main(){
  fastIo();
  cin>> nums_N >> nums_M >> start_V;

  for (int i = 0; i < nums_M; i++){
    int x, y;
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  
  for (int i = 0; i <= nums_N; i++)
    sort(graph[i].begin(), graph[i].end());
  
  dfs(start_V);
  cout << '\n';
  bfs(start_V);
  cout << '\n';

  return 0;
}