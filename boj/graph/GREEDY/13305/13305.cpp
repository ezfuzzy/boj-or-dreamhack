#include <iostream>
using namespace std;
typedef long long ll;

int oil[100001];
int city_distance[100000];

int main(){

    int n;
    ll cost=0;
    scanf("%d", &n);

    for (int i = 1; i <= n-1; i++)
        scanf("%d", &city_distance[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &oil[i]);
    
    int temp_oil = oil[1];
    for (int i = 1; i <= n-1; i++){
        temp_oil = min(temp_oil, oil[i]);   
        cost += (ll)temp_oil * (ll)city_distance[i];
    }
    
    printf("%lld\n", cost);
    return 0;
}