#include <iostream>
using namespace std;

int arr[11];

int main(){

    int n, k, temp_sum = 0, temp_num = 0;
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    
    while(temp_sum != k){
        if (temp_sum + arr[n] > k)
            n--;
        else {
            temp_sum += arr[n];
            temp_num++;
        }
    }
    printf("%d\n", temp_num);

    return 0;
}