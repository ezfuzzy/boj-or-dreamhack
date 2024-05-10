#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void fastIo(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}
typedef struct password{
  string site;
  string pwd;
}pw;
bool cmp (struct password a, struct password b){
  return a.site < b.site;
}
pw pwd_chain[100000];
int nums_N, nums_M; // <= 100,000
string temp_site;

int main(){
	fastIo();
	cin >> nums_N >> nums_M;

	for (int i = 0; i < nums_N; i++){
    cin >> pwd_chain[i].site >> pwd_chain[i].pwd;
	}
	sort(pwd_chain, pwd_chain+nums_N, cmp); 

  for (int i = 0; i < nums_M; i++){
    cin >> temp_site;

    int left=0, right=nums_N-1, ans;
    while(left <= right){
      int mid = (left+right)/2;

      if (pwd_chain[mid].site > temp_site){
        right = mid-1;
      } else if (pwd_chain[mid].site <= temp_site){
        left = mid+1;
        ans = mid;
      }
    }
    cout << pwd_chain[ans].pwd << '\n';
  }
  //asdasdada
  
	return 0;
}