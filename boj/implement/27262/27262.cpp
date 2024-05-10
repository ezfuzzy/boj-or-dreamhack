#include <iostream>
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
/** a,  거주하는 층 15 
    b,  현재 엘베 8
    c,  계단/한층 70
    d   엘베/한층 21 + 42 
 */
int live_N, temp_N, elevate_F, stairs_F, ans_E, ans_S;

int main(){
    fastIO();
    cin >> live_N >> temp_N >> stairs_F >> elevate_F;

    ans_E = (temp_N-1)*elevate_F + (live_N-1)*elevate_F;
    ans_S = (live_N-1)*stairs_F;

    cout << ans_E << " " << ans_S << "\n";

    return 0;
}   