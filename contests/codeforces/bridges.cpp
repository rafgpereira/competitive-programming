#include <iostream>
using namespace std;
int main(){
    int cases;
    cin >> cases;
    while(cases--){
        int islands, destroy;
        cin >> islands >> destroy;

        if(islands-destroy <= 1 ){
            cout << 1 << endl;
        } else{
            cout << islands << endl;
        }

    }

    return 0;
}