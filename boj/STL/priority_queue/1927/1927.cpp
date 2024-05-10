#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> min_pq;

int main(){

    int n, temp;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        scanf("%d", &temp);
        if (temp)
            min_pq.push(temp);
        else{
            if (min_pq.empty())
                printf("%d\n", 0);
            else{
                printf("%d\n", min_pq.top());
                min_pq.pop();
            }
        }
    }

    return 0;
}