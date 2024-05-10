#include <iostream>
#include <algorithm>
using namespace std;

struct Arr{
    int left;
    int right;
};

Arr arr[101];
int dp[101];

bool cmp(const Arr &a1, const Arr & a2){
    if(a1.left < a2.left)
        return true;
    else if(a1.left == a2.left)
        return a1.right < a2.right;
    else
        return false;
}

int main(){

    int cycle, temp_max = 0;
    scanf("%d", &cycle);

    for (int i = 1; i <= cycle; i++)
        scanf("%d %d", &arr[i].left, &arr[i].right);

    sort(arr+1, arr+cycle+1, cmp);

    for (int i = 1; i <= cycle; i++){
        dp[i] = 1;

        for (int j = 1; j < i; j++)
            if(arr[i].right > arr[j].right)
                dp[i] = max(dp[i], dp[j] + 1);
        
        temp_max = max(temp_max, dp[i]);
    }
    
    printf("%d\n", cycle - temp_max);


    return 0;
}