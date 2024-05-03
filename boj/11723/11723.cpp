#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void fastIo(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
int nums_N, cur_num;
string cur_command;
int main(){

    fastIo();
    cin >> nums_N;

    fastIo();
    cin >> nums_N; // <= 3,000,000

    for (int i = 0; i < nums_N; i++){
        cin >> cur_command;

        if (cur_command == "add"){
            cin >> cur_num;
        }
        else if (cur_command == "remove"){
            cin >> cur_num;
        }
        else if (cur_command == "check"){
            cin >> cur_num;
        }
        else if (cur_command == "toggle"){
            cin >> cur_num;
        }      
        else if (cur_command == "all"){
        }
        else if (cur_command == "empty"){
        }
    }
    return 0;
}


// vector<int> s;
// vector<int> base = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,16,17,18,19,20};

// int main(){

//     fastIo();
//     cin >> nums_N; // <= 3,000,000

//     for (int i = 0; i < nums_N; i++){
//         cin >> cur_command;

//         if (cur_command == "add"){
//             cin >> cur_num;
//             s.push_back(cur_num);
//         }
//         else if (cur_command == "remove"){
//             cin >> cur_num;
//             auto it1 = find(s.begin(), s.end(), cur_num);
//             if(it1 != s.end())
//                 s.erase(it1);
//         }
//         else if (cur_command == "check"){
//             cin >> cur_num;
//             auto it2 = find(s.begin(), s.end(), cur_num);
//             if(it2 != s.end()) // 있음
//                 cout << "1\n";
//             else
//                 cout << "0\n";
//         }
//         else if (cur_command == "toggle"){
//             cin >> cur_num;
//             auto it3 = find(s.begin(), s.end(), cur_num);
//             if(it3 != s.end())
//                 s.erase(it3);
//             else
//                 s.push_back(cur_num);
//         }      
//         else if (cur_command == "all"){
//             s = base;
//         }
//         else if (cur_command == "empty"){
//             s.clear();
//         }
//         cout << "size : " << s.size() << " : size // ";
//     }
//     return 0;
// }