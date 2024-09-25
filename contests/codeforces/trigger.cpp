#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned short cases;
    cin >> cases;
    while(cases--) {
        unsigned short qty;
        cin >> qty;
        string lamps{""};
        cin >> lamps;

        vector<int> positions{};

        if ( qty <= 2 && lamps[0] == '1'){
            cout << "NO" << endl;
            continue;
        }
        unsigned short on = 0;
        for(int i = 0; lamps[i] != '\0'; i++) {
            if(lamps[i] == '1'){
                on++;
                positions.push_back(i);
            }
        }
        if(on % 2 != 0 || (on == 2 && positions[1]-positions[0] == 1) ){
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }
}