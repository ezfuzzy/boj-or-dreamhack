#include <iostream>
using namespace std;

void print_star(int _row, int _col, int _num)
{
    if((_row/_num)%3 == 1 && (_col/_num)%3 == 1) 
        printf(" ");
    else
    {   
        if(_num / 3 == 0)
            printf("*");
        else
            print_star(_row,_col,_num/3);
    }
}
int main() {
    int num;
    cin >> num;

    for(int row = 0; row < num; row++)
    {
        for(int col = 0; col < num; col++)
            print_star(row,col,num);
        printf("\n");
    }
}