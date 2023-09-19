#include <iostream>

using namespace std;

int main(){
    int L,C;
    cin >> L;
    cin >> C;

    if((L + C) % 2 == 0)
        cout << "1";
    else cout << "0";
}
