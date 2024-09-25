#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int minA, minB;
    cin >> minA >> minB;
    
    int savedA = minA, savedB = minB;
    int sum = minA + minB;

    n--;
    while(n--){
        int a, b;
        cin >> a >> b;
        if(a+b < sum){
            sum = a+b;
            savedA = a;
            savedB = b;
        }
        if(a < minA ){
            minA = a;
        }
        if(b < minB){
            minB = b;
        } 

    }
    cout <<  "Par que gera a menor soma: "<< savedA << ",  " << savedB << endl;
    cout <<  "Menor A e B: "<< minA << ",  " << minB << endl;
}
