#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void fastIo(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

vector<int> graph[101];
queue<int> bfs_graph;
bool visited[101];

int nums_N, nums_M, ans=0;
//   <= 100
void dfs(int x){
  ans++;
  visited[x] = true;

  for (int i : graph[x]){
    if (!visited[i]){
      dfs(i);
    }
  }
}

void bfs(int x){
  bfs_graph.push(x);
  visited[x] = true;
  ans++;

  while(!bfs_graph.empty()){
    x = bfs_graph.front();
    bfs_graph.pop(); 
    
    for (int i : graph[x]){
      if (!visited[i]){
        bfs_graph.push(i);
        visited[i] = true;
        ans++;
      }  
    }
  }  
  
}
int main(){

  fastIo();
  cin >> nums_N >> nums_M;
  
  for (int i = 0; i < nums_M; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  
  // dfs(1);
  bfs(1);
  cout << ans-1 <<'\n';
  
  return 0;
}