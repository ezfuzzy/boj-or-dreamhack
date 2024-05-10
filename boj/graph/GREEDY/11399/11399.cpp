#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int main(){

    int n, temp_time = 0, result = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    
    sort(arr+1, arr+n+1);

    for (int i = 1; i <= n; i++){
        temp_time += arr[i];
        result += temp_time;
    }

    printf("%d\n", result);
    return 0;
}