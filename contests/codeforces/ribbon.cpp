#include <iostream>
using namespace std;

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        int peca, cor, qtyPeca;
        cin >> peca >> cor >> qtyPeca;

        int precisa = 0;
        if( peca % cor == 0){
            precisa = peca - (peca/cor);
        } else {
            precisa = peca - ((peca/cor) + 1);
        }

        if(qtyPeca >= precisa){
            cout << "NO" << endl;
        } else{
            cout << "YES" << endl;
        }
    }
}