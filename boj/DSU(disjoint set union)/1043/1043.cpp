#include <bits/stdc++.h>
using namespace std;
#define fastIo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, m, ans=0; // [1, 50]

int parents[53];
vector<int> partyPeople[51];

int find_root(int x){
  if(x != parents[x])
        return parents[x] = find_root(parents[x]);
    else
        return parents[x];
}

void union_root(int px, int py){
  px = find_root(px);
  py = find_root(py);

  if(px != py){
    if(px < py) parents[py] = px;
    else parents[px] = py;
  }
}

int main(){
  fastIo;

  int numOfTrue, nums;
  cin >> n >> m >> numOfTrue;
  int cycle_m = m;
  
  // init
  for (int i = 1; i <= n; i++)
    parents[i] = i;

  // 진실을 아는 사람들
  for (int i = 1; i <= numOfTrue; i++){
      cin >> nums;
      parents[nums] = 0;
  }

  // setting 
  int idx = 1;
  while(cycle_m--){ // 50
    
    cin >> nums;

    int curRoot=51; // <= 50
    for (int i = 1; i <= nums; i++){
      int a;
      cin >> a; 
      partyPeople[idx].push_back(a);
      
      curRoot = min(curRoot, a);
    }

    for (int i: partyPeople[idx]){
      union_root(curRoot, i);
    }

    idx++;
  }

  // solve 
  for (int i = 1; i <= m; i++){
    for (int curParty: partyPeople[i]){
      if(find_root(curParty)){
        ans++;
        break;
      }
    }    
  }

  cout << ans;
  return 0;
}