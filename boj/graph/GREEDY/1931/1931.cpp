#include <iostream>
#include <algorithm>
using namespace std;

struct Arr{
    int start;
    int end;
};

Arr arr[100001];
bool cmp(const Arr &a1, const Arr &a2){
    if(a1.start < a2.start)
        return true;
    else if (a1.start == a2.start)
        return a1.end < a2.end;
    else
        return false;
}

int main(){
    int n, result = 1;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    sort(arr+1, arr+n+1, cmp);

    int temp_start = arr[1].start, temp_end = arr[1].end;
    
    for (int i = 2; i <= n; i++)
    {
       if (temp_end <= arr[i].start ){
            temp_start = arr[i].start;
            temp_end = arr[i].end;
            result++;
        }
        else if(temp_start <= arr[i].start && arr[i].end <= temp_end){
            temp_start = arr[i].start;
            temp_end = arr[i].end;
        }
        
    }

    printf("%d\n", result);
    return 0;
}