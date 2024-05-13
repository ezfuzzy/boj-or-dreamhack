#include <iostream>
#include <algorithm>
using namespace std;

void fastIo(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

int a, b, c, x, y, ans=0;

int main(){
  fastIo();
  cin >> a >> b >> c >> x >> y;
  if(a+b > (c<<1)){
    int nums_c = (min(x,y)<<1);
    ans = c*nums_c;

    if(x>y){
      if (a > (c<<1))
        ans += ((c*(x-y)) << 1);
      else
        ans += a*(x-y);
    }
    else{
      if (b > (c<<1))
        ans += ((c*(y-x)) << 1);
      else
        ans += b*(y-x);
    }
  }
  else{
    ans = a*x+b*y;
  }
  
  cout << ans << '\n';

  return 0;
}
