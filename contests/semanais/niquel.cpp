#include <iostream>
using namespace std;
int main(){
    char a, b, c;
    cin >> a >> b >> c;
    if(a==b and b==c) {
        cout << "Won" << endl;
        return 0;
    }
    cout << "Lost" << endl;
}