#include <iostream>
using namespace std;

void fastIo(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
int nums_N, temp, ans=0, max_N=0;
int main(){
    fastIo();
    
    cin >> nums_N;
    for (int i = 0; i < nums_N; i++)
    {
        cin >> temp;
        ans += temp;
        max_N = max(max_N, temp);
    }
    
    cout << ans - max_N << '\n';

    return 0;
}