#include <bits/stdc++.h>
using namespace std;

int main() {
    int cases;
    cin >> cases;

    while(cases--){
        int qty, price, promotion;
        cin >> qty >> price >> promotion;
        int total = 0;
        if(promotion < 2 * price){
            if(qty % 2 == 0) {
                total += (qty/2)*promotion;
            } else {
                total += ((qty-1)/2)*promotion + price;
            }
        } else {
            total = qty * price;
        }
        cout << total << endl;
    }

    return 0;
}