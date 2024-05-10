#include <iostream>
using namespace std;

int a[501];
int dp[501][501];

void fast_io(){
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main(){
    fast_io();
    
    int n, x, y, temp;

    cin >> n >> temp >> y;

    for (int cnt = 1; cnt < n; cnt++){
        cin >> x >> y;
        a[cnt] = temp*x*y; // a[i] : i-1 번째 행렬과 i번째 행렬을 곱했을때 곱셈 수.
        temp = x;
    }
    
    for (int cycle = 1; cycle <= n; cycle++){
        int i =1;
        int j = cycle+1;

        for (int l = 0; l < n-cycle ; l++){
            dp[i][j] = 1e9;
            for (int m = j-cycle; m <= j-1; m++){
                dp[i][j] = min(dp[i][j], dp[i][m]+dp[m+1][j] + a[i]); // ?? 
            }
            i++;
            j++;
        }
    }
    
    cout << dp[1][n] << "\n";

    return 0;
}