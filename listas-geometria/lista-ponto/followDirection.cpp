#include <bits/stdc++.h>
using namespace std;
using Point = pair<int, int>;
#define x first
#define y second
// Para cada caso recebe uma string de passos,
// e a partir da origem, segue os passos
// direita, esquerda cima e baixo
// e determina se ele passou por (1, 1)
int main() {
    int cases;
    cin >> cases;
    while (cases--){
        Point P{0, 0};
        bool resp = false;
        int steps;
        cin >> steps;
        char commands[steps];
        cin >> commands;
        for (auto &c : commands) {
            if (c == 'L')
                P.x--;
            else if (c == 'R')
                P.x++;
            else if (c == 'U')
                P.y++;
            else
                P.y--;
            if (P.x == 1 && P.y == 1){
                resp = true;
                break;
            }
        }
        cout << (resp ? "YES" : "NO") << endl;
    }
}