a, b = map(int, input().split(" "))
print(a//b)
print(a%b)

#  #include <bits/stdc++.h>
#  using namespace std;

#  string a, b, ans_mod;
#  int ans_div;

#  bool isBigger(string _a, string _b){
#    if(_a.size() > _b.size()) return true;
#    else if(_a.size() < _b.size()) return false;

#    return _a >= _b;
#  }

#  string sub(string _a, string _b){  a >= b가 기본 세팅 

#    string ret = "";
#    for (int i = 1; i <= _b.size(); i++){
#      int curA = _a[_a.size()-i] - '0';
#      int curB = _b[_b.size()-i] - '0';

#      curA - curB < 0 ? curA += 10, _a[_a.size()-i-1]-- : 0;
    
#      ret = to_string(curA - curB) + ret;
#    }

#    int idx = _a.size() - _b.size() - 1;
#    for (int i = idx; i >= 0; i--){
#      if(_a[i] < '0') {
#        _a[i] += 10;
#        _a[i-1]--;
#      }
#      ret = _a[i] + ret;
#    }
  
#    return ret;
#  }

#  string div(string _a, string _b){
#    if(!isBigger(_a, _b)) return _a;
  
#    while(isBigger(_a, _b) && _a != "0"){
#      _a = sub(_a, _b);
#      ans_div++;
    
#      for (int i = 0; i < _a.size(); i++){
#        if(_a[i] == '0') {
#          _a.erase(0, 1); 
#          i--;
#        } else break;
#      }
#    }
#    return _a;
#  }

#  int main() {

#    cin >> a >> b;
#    ans_mod = a;
  
#    ans_mod = div(a, b);
  
#    for (int i = 0; i < ans_mod.size(); i++){
#      if(ans_mod[i] == '0') {
#        ans_mod.erase(0, 1); 
#        i--;
#      } else break;
#    }
 
#    if(ans_mod == "") ans_mod = "0";
#    cout << ans_div << '\n' << ans_mod;
#    return 0;
#  }