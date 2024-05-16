#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int nums_N, blue_ans=0, white_ans=0, temp;

int arr[129][129];
bool isSame[129][129];

int isSameColor(int _n, int _dx, int _dy){
  if (isSame[_dx][_dy]) return -1; // already checked that is smae color
  int color = arr[_dx][_dy];
  for (int i = _dx; i < _dx+_n; i++)
    for (int j = _dy; j < _dy+_n; j++)
      if (arr[i][j] != color) return 0;

  isSame[_dx][_dy] = true;
  // for (int i = _dx; i < _dx+_n; i++)
  //   for (int j = _dy; j < _dy+_n; j++)
  //     isSame[_dx][_dy] = true;
  if (color) return 1; // bule: 1
  else return 2;  // white: 2
}

void conquer(int n, int dx, int dy){
  if (n){
    // case 1: x = dx ~ n/2-1, y = dy ~ n/2-1
    temp = isSameColor(n/2, dx, dy);
    if (!temp)  conquer(n/2, dx, dy);
    else if (temp == 1)  blue_ans += 1;
    else if (temp == 2)  white_ans += 1;
    
    // case 2: x = dx ~ n/2-1, y = dy + n/2 ~ n-1
    temp = isSameColor(n/2, dx, dy + n/2);
    if (!temp)  conquer(n/2, dx, dy + n/2);
    else if (temp == 1)  blue_ans += 1;
    else if (temp == 2)  white_ans += 1;
    
    // case 3: x = dx + n/2 ~ n-1, y = dy ~ n/2-1
    temp = isSameColor(n/2, dx + n/2, dy);
    if (!temp)  conquer(n/2, dx + n/2, dy);
    else if (temp == 1)  blue_ans += 1;
    else if (temp == 2)  white_ans += 1;

    // case 4: x = dx + n/2 ~ n-1, y = dy + n/2 ~ n-1
    temp = isSameColor(n/2, dx + n/2, dy + n/2);
    if (!temp)  conquer(n/2, dx + n/2, dy + n/2);
    else if (temp == 1)  blue_ans += 1;
    else if (temp == 2)  white_ans += 1;
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> nums_N;
  for (int i = 0; i < nums_N; i++)
    for (int j = 0; j < nums_N; j++)
      cin >> arr[i][j];

  temp = isSameColor(nums_N, 0, 0);
  isSame[0][0] = false;
  if(!temp) conquer(nums_N, 0, 0);
  else if (temp == 1) blue_ans += 1;
  else if (temp == 2)  white_ans += 1;

  cout << white_ans << '\n' << blue_ans << '\n';
  return 0;
}