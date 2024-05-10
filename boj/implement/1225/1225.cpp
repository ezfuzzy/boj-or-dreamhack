#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

void fastIo(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main(){
    fastIo();

    string a, b;
    cin >> a >> b;
    ll ans=0;

    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < b.size(); j++){
            int n1 = a[i] - '0';
            int n2 = b[j] - '0';
            ans += n1*n2;
        }   
    }
    
    cout << ans << "\n";
    return 0;
}