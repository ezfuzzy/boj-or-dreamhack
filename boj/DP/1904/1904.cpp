#include <iostream>
using namespace std;
// % 15746
long long answer_sheet[1000000];

int main(){

    int num;
    scanf("%d", &num);

    answer_sheet[0] = 0;
    answer_sheet[1] = 1;
    answer_sheet[2] = 2;

    for (int i = 3; i <= num; i++)
        answer_sheet[i] = (answer_sheet[i-2] + answer_sheet[i-1]) % 15746;
    
    printf("%lld", answer_sheet[num]);

    return 0;
}