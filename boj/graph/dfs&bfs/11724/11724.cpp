#include <iostream>
#include <vector>
using namespace std;

int n, m, ans=0; // 1 <= n <= 1000, 0 <= m <= 500,000
vector<int> graph[1001];
vector<int> sheet;
bool isVisited[1001][1001], isChecked, isValid;

void dfs(int _n){
  for(int i : graph[_n]){
    isChecked = true;
    if(!isVisited[_n][i]){
      isVisited[_n][i] = true;
      isVisited[i][_n] = true;
      isValid = true;
      dfs(i);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= n; i++){
    sheet.push_back(i);
    dfs(i);
    if(isValid)
      ans++;
    else if(!isChecked)
      ans++;
    
    isChecked = false;
    isValid = false;
  }

  cout << ans;
  return 0;
} 