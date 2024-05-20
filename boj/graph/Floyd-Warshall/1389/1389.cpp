#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 200000000
using namespace std;

int n, m;
int dist[101][101];			// dist[i][j] : i -> j로 가는 비용
vector<int> adjlist[101];	// 인접리스트

int solve() {
	// 플로이드 와샬 
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	// 케빈 베이컨 수가 가장 작은 노드 찾기
	int ret = 1;
	int sum = INF;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) tmp += dist[i][j];
		if (sum > tmp) {
			ret = i;
			sum = tmp;
		}
	}
	return ret;
}

void init() {
	// dist 배열 초기화
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		dist[u][v] = 1;
		dist[v][u] = 1;
	}
}

int main() {
	fastio;

	init();
	cout << solve();
}

//*===============================
//*
//* using bfs algorithm
//*
//* ==============================
// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// int n, m, bacon=0, ans=200000, minBaconNode;
// vector<int> friends[101];
// queue<pair<int,int>> bfsQ;
// int visited[101] = {0,};

// void bfs(int _node){

//     // reset 
//   bacon = 0;
//   for (int j = 1; j <= n; j++)
//     visited[j] = false;

//   bfsQ.push(make_pair(_node, 0));
//   visited[_node] = true;

//   int depth=0;
//   while(!bfsQ.empty()){
//     _node = bfsQ.front().first;
//     depth = bfsQ.front().second;
//     bfsQ.pop();

//     for (int i: friends[_node]){
//       if(!visited[i]){
//         bfsQ.push(make_pair(i,depth+1));
//         visited[i] = true;
//         bacon += depth+1;
//       }
//     }
//   }
// }


// int main(){

//   cin >> n >> m;
  
//   for (int i = 0; i < m; i++){
//     int a, b;
//     cin >> a >> b;
//     friends[a].push_back(b);
//     friends[b].push_back(a);
//   }

//   for (int i = 1; i <= n; i++){
//     bfs(i);
//     if(ans > bacon){ // same value => minBaconNode must be min idx;
//       ans = bacon;
//       minBaconNode = i;
//     }
//   }
  
//   cout << minBaconNode;
//   return 0; 
// }