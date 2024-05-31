#include <bits/stdc++.h>
using namespace std;
#define fastIo ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, normal_ans=0, colorBlind_ans=0;
char arr[101][101];
bool isVisited[101][101];
queue<pair<int,int>> bfsQ;

void bfs(int x, int y, bool isColorBlind){
	
	char curColor = arr[x][y];
	bfsQ.push({x,y});
	isVisited[x][y] = true;
	
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };

	bool isValid = false;
	while(!bfsQ.empty()){
		x = bfsQ.front().first;
		y = bfsQ.front().second;
		bfsQ.pop();

		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx >= 0 && nx < n && ny >= 0 && ny < n ){
				if(!isVisited[nx][ny] && arr[nx][ny] == curColor){
					bfsQ.push({nx,ny});
					isVisited[nx][ny] = true;
					isValid = true;
				}
			}
		}
	}

	if(isColorBlind) colorBlind_ans++;
	else normal_ans++;
}

int main(){

	fastIo;

	cin >> n; // 1 ~ 100 
    
	string str;
	for (int i = 0; i < n; i++){ // input 
		cin  >> str;
		for (int j = 0; j < n; j++){    
				arr[i][j] = str[j];
		}
	}
    
	for (int i = 0; i < n; i++){ // for normal
		for (int j = 0; j < n; j++){
			if(!isVisited[i][j])
				bfs(i,j, false);
		}
	}
	
	for (int i = 0; i < n; i++){ // initialize
		for (int j = 0; j < n; j++){
			isVisited[i][j] = false;
			if(arr[i][j] == 'G') arr[i][j] = 'R';
		}
	}
	

	for (int i = 0; i < n; i++){ // for color blindness
			for (int j = 0; j < n; j++){
				if(!isVisited[i][j])
					bfs(i,j, true);
			}
		}


	cout << normal_ans << ' ' << colorBlind_ans << '\n';
	return 0;
}