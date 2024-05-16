#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll find_sqrt(ll x){
    ll temp = 0;
    while(temp*temp <= x)
        temp++;
    return temp-1;
}
ll find_gcd(ll x, ll y){

    if (y==0)
        return x;
    else
        return find_gcd(y, x%y);
    
}
int main(){
    ll a, b;
    scanf("%lld %lld", &a, &b);

    ll d = int(find_sqrt(b)) - int(find_sqrt(a));
    ll m = b-a;

    if(!d)
        printf("%d\n", 0);
    else{   
        ll m_gcd = find_gcd(d, m);
        printf("%lld/%lld\n", d/m_gcd, m/m_gcd);
    }
    return 0;
}