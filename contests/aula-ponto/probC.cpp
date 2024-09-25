#include <bits/stdc++.h>
using namespace std;

int cres(int x){

    string temp = to_string(x);
    sort(temp.begin(), temp.end());
    int resultado = stoi(temp);
    return resultado;
}

bool compararDecrescente(char a, char b) {
    return a > b;
}

int decres(int x) {

    string temp = to_string(x);

    sort(temp.begin(), temp.end(), compararDecrescente);

    int resultado = stoi(temp);

    return resultado;
}


int source( int num, int iter) {
    int sub = decres(num) - cres(num);
    iter--;
    if(iter==0){
        return sub;
    }
    return source(sub, iter);

}

int main() {
    int iter;
    int num;
    cin >> num;
    cin >> iter;

    if(iter>=num || iter == 0){
        cout << num;
    } else {
        cout << source(num, iter);
    }
}