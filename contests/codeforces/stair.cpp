#include <iostream>
using namespace std;

int main(){
    unsigned short cases;
    cin >> cases;
    while(cases--) {
        unsigned short a, b, c;
        cin >> a >> b >> c;

        if( a < b && b < c) {
            cout << "STAIR" << endl;
        } else if ( a < b && b > c) {
            cout << "PEAK" << endl;
        } else {
            cout << "NONE" << endl;
        }
    }
}