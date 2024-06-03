#include <bits/stdc++.h>
using namespace std;
#define fastIo ios_base::sync_with_stdio(0); cin.tie(0);

vector<vector<pair<int, int>>> tree(10001);
bool visited[10001];
int n, from, to, weight;

pair<int, int> dfs(int node){
  visited[node] = true;
  pair<int, int> ret = {node, 0};

  for (pair<int, int> curNode: tree[node]){
    if(!visited[curNode.first]){
      pair<int, int> nextNode = dfs(curNode.first);
      nextNode.second += curNode.second;
      if(nextNode.second > ret.second)  
        ret = nextNode;
    }
  }
  return ret;
}


int main(){
  fastIo

  cin >> n;
  for (int i = 0; i < n-1; i++){
    cin >> from >> to >> weight;
    tree[from].push_back({to, weight});
    tree[to].push_back({from, weight});
  }

  memset(visited, 0, n+1);
  pair<int, int> firstNode = dfs(1);
 
  memset(visited, 0, n+1);
  pair<int, int> secondNode = dfs(firstNode.first);      


  cout << secondNode.second;
  return 0;
}