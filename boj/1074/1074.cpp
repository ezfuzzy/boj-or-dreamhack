#include <iostream>
#include <cmath>
using namespace std;

int nums_N, row, col;

int main(){

  cin>> nums_N >> row >> col;
  int temp_row=row, temp_num, row_ans=0;

  while(temp_row){
    temp_num = int(log2(temp_row));
    temp_row -= pow(2, temp_num);
    row_ans += 2*pow(pow(2, temp_num), 2);
  }

  int temp_col=col, col_ans=0;

  while(temp_col){
     temp_num = int(log2(temp_col));
     temp_col -= pow(2, temp_num);
     col_ans += pow(pow(2, temp_num), 2);
  }

  cout << row_ans + col_ans << '\n';
  return 0;
}