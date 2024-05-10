#include <iostream>
#include <vector>
using namespace std;

void fastIo(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int nums_N, nums_K, temp=0;
vector<int> yoseph;
int main(){
    
    fastIo();
    cin >> nums_N >> nums_K;
    
    cout << "<";
    for (int i = 0; i < nums_N; i++)
        yoseph.push_back(i+1);
    
    while(yoseph.size()){
        temp += nums_K-1; 
        temp %= yoseph.size();
       
        if (yoseph.size() != 1)
            cout << yoseph[temp] << ", ";
        else 
            cout << yoseph[temp] << ">\n";

        yoseph.erase(yoseph.begin()+temp);       
    }

    return 0;
}