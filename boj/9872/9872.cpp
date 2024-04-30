#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int nums_N, ans=1; // <= 1000
string s1, s2, s3, str; // : A~Z, 1~10Size, 
vector<pair<string, int>> list;
bool isRepeated;
int main(){

    cin >> nums_N;

    for (int i = 0; i < nums_N; i++){
        
        cin >> s1 >> s2 >> s3;
        
        // sort 
        string arr[] = {s1, s2, s3};
        sort(arr, arr+3);
        str = arr[0] + arr[1] + arr[2];

        int idx = 0;
        isRepeated = false;
        while (idx < list.size()){
            if (!list[idx].first.compare(str)){
                isRepeated = true;
                break;
            }
            idx++;
        }

        // duplication search
        if (isRepeated){ // true
            list[idx].second++;
            ans = max(ans, list[idx].second);
        }
        else 
            list.push_back(make_pair(str, 1));

        
            /*
        s1, s2, s3를 입력받고 정렬한다. 
        일치하는 항목이 없으면 해당  cnt와 함께 저장한다
        pair<string, int> 형식으로 가도 되겠다

        일치하는 항목이 있으면 3번 인덱스의 cnt를 증가시킨다.
        cnt는 따로 변수로 저장하는 것이 아니라
        그냥 int를 넣어둔다. 
        >> if (duplication){
            group s1[3].second++;
        }
        max cnt를 계속 저장해둔다.
        */
    }
    
    cout << ans << '\n';
    return 0;
}