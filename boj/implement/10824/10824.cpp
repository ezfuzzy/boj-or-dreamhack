#include <iostream>
using namespace std;
typedef long long ll;
void fastIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll a, b, c, d, temp, ans;
int main(){
    fastIO();
    cin >> a >> b >> c >> d;
    
    temp = b;
    while(temp){
        if (temp /= 10)
            a *= 10;
    }
    ans = a*10+b;
    
    temp = d;
    while(temp){
        if (temp /= 10)
            c *= 10;
    }
    ans += c*10 + d;

    cout << ans << "\n";
    return 0;
}