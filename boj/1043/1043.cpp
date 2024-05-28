#include <bits/stdc++.h>
using namespace std;
#define fastIo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, m, ans=0; // [1, 50]
vector<int> parents;
vector<int> partyPeople[51];
vector<int> fact;

int find_root(int x){
  if(parents[x] == x) return x;
  else if (parents[x] == 0) return 0;
  
  return find_root(parents[x]); 
}

void union_root(int x, int y){
  x = find_root(x);
  y = find_root(y);

  if(x != y){ // parent가 fact에 있는 사람이 root가 되어야함
    bool isTrue = find(fact.begin(), fact.end(), y) != fact.end();
    if(isTrue){  
      parents[x] = y;
    } else {
      if(x < y) parents[y] = x;
      else parents[x] = y;
    }
  }
}

int main(){
  fastIo;

  int numOfTrue, nums;
  cin >> n >> m >> numOfTrue;
  int cycle_m = m;
  // init
  parents.push_back(-1);
  for (int i = 1; i <= n; i++){
    parents.push_back(i);
  }

  // 진실을 아는 사람들
  fact.push_back(0);
  for (int i = 1; i <= numOfTrue; i++){
      cin >> nums;
      fact.push_back(nums);
  }

  // setting 
  int idx = 1;
  while(cycle_m--){ // 50
    
    cin >> nums;

    int curRoot=51;
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

  // if know turth: root = 0
  for (int i = 1; i <= numOfTrue; i++){
    parents[fact[i]] = 0;
  }

  // for (int i = 1; i <= n; i++){
  //   cout << parents[i] << " ";
  // }


  // solve 
  for (int i = 1; i <= m; i++){
    for (int curParty: partyPeople[i]){
      // cout << "curParty: " << curParty << " root: " << find_root(curParty) << endl;
      if(find_root(curParty)){
        ans++;
        break;
      }
    }    
  }

  cout << ans;
  return 0;
}