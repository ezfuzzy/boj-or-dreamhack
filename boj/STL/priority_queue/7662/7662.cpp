#include <bits/stdc++.h>
using namespace std;


priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
map<int, int> HeapMap;
int T, k, inputNum;
char c;

void delMax(){
  if(!maxHeap.empty()){
    HeapMap[maxHeap.top()]--;
    maxHeap.pop();
  }
}

void delMin(){
  if(!minHeap.empty()){
    HeapMap[minHeap.top()]--;
    minHeap.pop();
  }
}


void syncHeap(){
  while(!maxHeap.empty() && HeapMap[maxHeap.top()] == 0)
    maxHeap.pop();
  while(!minHeap.empty() && HeapMap[minHeap.top()] == 0)
    minHeap.pop();
}

int main(){

  cin >> T;

  while(T--){
    //reset 
    HeapMap.clear();
    while(!maxHeap.empty())
      maxHeap.pop();
    while(!minHeap.empty())
      minHeap.pop();

    cin >> k;

    for (int i = 0; i < k; i++){
      cin >> c >> inputNum;

      if(c == 'I'){
        maxHeap.push(inputNum);
        minHeap.push(inputNum);
        
        if(HeapMap.count(inputNum) == 0)
          HeapMap[inputNum] = 1;
        else
          HeapMap[inputNum]++;
      }
      else if(c == 'D'){
        if(inputNum == 1)
          delMax();
        else 
          delMin();
        syncHeap();
      }
    }
    
    syncHeap();
    if(maxHeap.empty() || minHeap.empty())
      cout << "EMPTY" << "\n";
    else{
      cout << maxHeap.top() << " " << minHeap.top() << "\n";
    }

  }
  
  return 0;
}
