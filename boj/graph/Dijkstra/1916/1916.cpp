#include <bits/stdc++.h>
using namespace std;
#define fastIo ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 10e8
int n, m; // n: [1,1000], m: [1,100,000]
int from, to, cost;

vector<vector<pair<int, int>>> costTable(1001); // 각 간선의 비용을 저장하기 위한 인접 리스트
priority_queue<pair<int, int>> pq; // 최소 거리를 가진 노드들을 저장하기 위한 우선순위 큐
int dist[1001]; // from노드에서 각 노드까지의 최소 거리를 저장하기 위한 배열

void init(){
  // 입력값을 읽어옴
  cin >> n >> m;
  for (int i = 0; i < m; i++){
    cin >> from >> to >> cost;
    costTable[from].push_back({cost, to});
  }

  cin >> from >> to;
  for (int i = 1; i <= n; i++){
    dist[i] = INF;
  }
}

void solve(){
  dist[from] = 0;
  pq.push({0, from});

  int curCost, curNode;
  while(!pq.empty()){
    curCost = -pq.top().first;
    curNode = pq.top().second;
    pq.pop();

    if(dist[curNode] < curCost) continue; // 이미 최소

    for(pair<int, int> curCity: costTable[curNode]){
      int nCost = curCost + curCity.first;
      int nNode = curCity.second;

      // 새로운 거리가 현재까지의 최소 거리보다 작은 경우 업데이트
      if(dist[nNode] > nCost){
        dist[nNode] = nCost;
        pq.push({-nCost, nNode}); // -를 통해 순위 조정 이웃 노드를 우선순위 큐에 추가
      }
    }
  }
  cout << dist[to];
}

int main(){
  fastIo
  init();
  solve();
  return 0;
}