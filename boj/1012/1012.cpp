#include <iostream>
using namespace std;

void fastIo(){
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int fac(int n){
    int result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

int case_T, temp_N, ans, temp_c;

int main() {

    fastIo();
    cin >> case_T;

    for (int main_cycle = 0; main_cycle < case_T; main_cycle++){
        
        cin >> temp_N;
        ans = 0;

        // case 1:
        ans++;
        // case 2:
        for (int i = 1; i <= temp_N/2; i++){
            temp_c = temp_N - i;
            ans += (fac(temp_c) / (fac(i)*fac(temp_c-i)));
        }
        // case 3:
        for (int i = 1; i <= temp_N/3; i++){
            temp_c = temp_N - i*2;
            ans += (fac(temp_c) / (fac(i)*fac(temp_c-i)));
        }
        // case 4:
        if(temp_N >= 5) {
            for (int three_cnt = 1; three_cnt <= (temp_N-2)/3; three_cnt++){
                for (int two_cnt = 1; two_cnt <= (temp_N-3)/2; two_cnt++){
                    temp_c = temp_N - three_cnt*2 - two_cnt;
                    ans += (fac(temp_c) / (fac(three_cnt)*fac(two_cnt)*fac(temp_c-three_cnt-two_cnt)));
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}