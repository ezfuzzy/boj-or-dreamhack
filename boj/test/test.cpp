#include <bits/stdc++.h>
using namespace std;

int n = 20;

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

	int m;
	cin>>m;

	int s = 0; //공집합
	string cmd;
	while(m--){
		cin>>cmd;

		int x;
		if(cmd == "add"){
			cin>>x;
			x--;
			s = (s | (1 << x));
		} else if(cmd == "remove"){
			cin>>x;
			x--;
			s = (s & ~(1 << x));
		} else if(cmd == "check"){
			cin>>x;
			x--;
			int check = (s & (1 << x));
			cout<<(check ? 1 : 0)<<'\n';
		} else if(cmd == "toggle"){
			cin>>x;
			x--;
			s = (s ^ (1 << x));
		} else if(cmd == "all"){
			s = (1 << n) - 1;
		} else{ //empty
			s = 0;
		}
    cout << s << " ";
	}

	return 0;
}