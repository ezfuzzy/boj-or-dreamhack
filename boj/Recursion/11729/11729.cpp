#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int _nod, int _from, int _by, int _to);

int main(){

    int nod;
    cin >> nod;

    cout << (1<<nod) -1 << endl;
    hanoi(nod, 1, 2, 3);

    return 0;
}

void hanoi(int _nod, int _from, int _by, int _to){

    if (_nod == 1){
        printf("%d %d\n", _from, _to);
        return;
    }
    hanoi(_nod-1, _from, _to, _by);
    printf("%d %d\n", _from, _to);
    hanoi(_nod-1, _by, _from, _to);
}