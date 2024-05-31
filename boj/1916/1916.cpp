#include <bits/stdc++.h>
using namespace std;
#define fastIo ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 10e8;
int n, m; // n: [1,1000], m: [1,100,000]
int from, to, cost;

int costTable[1001][1001];
vector<vector<pair<int, int>>> costTable[1001];
vector<pair<int, int>> cost[1001];

void init(){
  cin >> n >> m;
  
  for (int i = 0; i < m; i++){
    cin >> from >> to >> cost;
    costTable[from].push_back({to, cost});
    cost[from].push_back({to, cost});
    costTable[from].push_back(to);
  }
  
}

void solve(){
  
  
}

int main(){
  fastIo
  init();
  solve();
  return 0;
}