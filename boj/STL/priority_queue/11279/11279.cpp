#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main(){

    int n, temp;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        scanf("%d", &temp);
        if (temp)
            pq.push(temp);
        else{
            if (pq.empty())
                printf("%d\n", 0);
            else{
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
    }

    return 0;
}