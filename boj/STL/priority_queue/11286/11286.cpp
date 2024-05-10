#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct abs_cmp{
    bool operator()(int a, int b){
        if (abs(a) == abs(b))
            return a>b;
        return abs(a)>abs(b);
    }
};

priority_queue<int, vector<int>, abs_cmp> abs_pq;

int main(){

    int n, temp;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        scanf("%d", &temp);

        if (temp)
            abs_pq.push(temp);
        else{
            if (!abs_pq.empty()){
                printf("%d\n", abs_pq.top());
                abs_pq.pop();
            }
            else
                printf("%d\n", 0);
        }
    }
    
    return 0;
}