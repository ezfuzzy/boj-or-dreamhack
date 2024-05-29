#include <bits/stdc++.h>
using namespace std;
#define fastIo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n; // [2, 100,000]

vector<int> tree[100001];
int parents[100001];
bool visited[100001];

void dfs(int x){

  visited[x] = true;

  for (int curNode: tree[x]){
    if(!visited[curNode]){
      visited[curNode] = true;
      parents[curNode] = x;
      dfs(curNode);
    }
  }
}
int main() {

  fastIo;

  cin >> n;
  
  parents[1] = 1;
  
  int a, b;
  for (int i = 0; i < n-1; i++){
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  
  dfs(1);
  
  for(int i = 2; i <= n; i++){
    cout << parents[i] << '\n';
  }
  return 0;
}