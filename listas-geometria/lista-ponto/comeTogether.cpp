#include <bits/stdc++.h>
using namespace std;
using Point = pair<int, int>;
#define x first
#define y second
// Para cada caso, recebo a posição A, onde B e C estão juntos,
// e depois onde B e C moram. Deve imprimir quantas posições
// eles andam juntos caso eles vão
// para suas casas pelo caminho mais curto.
int main() {
    int cases; cin >> cases;
    while (cases--) {
        Point A, B, C;
        cin >> A.x >> A.y; cin >> B.x >> B.y; cin >> C.x >> C.y;
        int moves = 1;
        bool betweenX = false, betweenY = false;
        // Analiso se estão entre suas casas, tanto em X quanto em Y
        if ((C.x > A.x && A.x > B.x) || (B.x > A.x && A.x > C.x))
            betweenX = true;
        if ((C.y > A.y && A.y > B.y) || (B.y > A.y && A.y > C.y))
            betweenY = true;
    // pego as diferenças entre as casas deles e onde eles estão em X e Y
        int difABX = abs(A.x - B.x), difACX = abs(A.x - C.x);
        int difABY = abs(A.y - B.y), difACY = abs(A.y - C.y);
        // Analiso as 4 únicas possibilidades:
        if (betweenX && !betweenY) {// Estão entre suas casas em X
            if (difABY > difACY) moves += difACY;
            else moves += difABY; // Soma a menor distancia em Y
        }
        if (!betweenX && betweenY){// Estão entre suas casas em Y
            if (difABX > difACX) moves += difACX;
            else moves += difABX;//Soma a menor distância em X
        }
        if (!betweenX && !betweenY){ // Não estão entre nenhuma, andam a menor em X e Y
            if (difABX > difACX)
                moves += difACX;
            else
                moves += difABX;
            if (difABY > difACY)
                moves += difACY;
            else
                moves += difABY;
        }
        // O quarto caso, quando estão entre X e Y, só ficam 1 juntos.
        cout << moves << endl;
    }
}