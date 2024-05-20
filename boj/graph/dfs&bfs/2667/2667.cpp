#include <bits/stdc++.h>
using namespace std;

int n;
int apartments[25][25];
vector<int> apart_list;
queue<pair<int, int>> bfsQ;

int bfs(int _x, int _y){
  if(apartments[_x][_y] == 0) return 0;

  bfsQ.push(make_pair(_x, _y));

  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {-1, 1, 0, 0};
  int noh=1;// number of home
  while(!bfsQ.empty()){
    _x = bfsQ.front().first;
    _y = bfsQ.front().second;
    bfsQ.pop();

    for (int i = 0; i < 4; i++){
      if(_x+dx[i] >= 0 && _y+dy[i] >= 0 && _x+dx[i] < n && _y+dy[i] < n){
        if(apartments[_x+dx[i]][_y+dy[i]] == 1){
          bfsQ.push(make_pair(_x+dx[i], _y+dy[i]));
          apartments[_x+dx[i]][_y+dy[i]] = 0;
          apartments[_x][_y] = 0;
          noh++;
        }
      }
    } 
  }
  return noh;
}

int main(){

  cin >> n;
  
  string str;
  for (int i = 0; i < n; i++){
    cin >> str;
    for (int j = 0; j < n; j++){
      apartments[i][j] = str[j] - '0';
    }  
  }
  
  //process
  for (int i = 0; i < n; i++){
    for(int j = 0; j < n; j ++){
      int temp = bfs(i,j);
      if(temp)
        apart_list.push_back(temp);
    }
  }

  // answer 
  sort(apart_list.begin(), apart_list.end());
  cout << apart_list.size() << '\n';
  for (int i = 0; i < apart_list.size(); i++){
    cout << apart_list[i] << '\n';
  }
  
  return 0;
}