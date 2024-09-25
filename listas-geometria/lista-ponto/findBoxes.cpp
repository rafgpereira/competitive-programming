#include <bits/stdc++.h>
using namespace std;
using Point = pair<int, int>;
#define x first
#define y second
// Para cada caso recebe posições de caixas.
// Deve retornar a menor quantidade de movimentos necessários para,
// saindo da origem, passar por todas as caixas e retornar.
// AS CAIXAS ESTAO SEMPRE NO EIXO X OU Y.
int main() {
    // A lógica é pegar as maiores e menores cordenadas x e y,
    // soma e multiplica por 2 (ida e volta);
    int cases; cin >> cases;
    while (cases--) {
        int qtyBox; cin >> qtyBox;
        // Inicializo o set com 0 para caso nao tenha maiores ou menores em determinado eixo.
        set<int> pointsX{0}, pointsY{0};
        while (qtyBox--) {
            Point P;
            cin >> P.x >> P.y;
            pointsX.insert(P.x); pointsY.insert(P.y);// Insert para inserir no set.
        }
        // abs pega valor absoluto. Usa-se * para acessar o valor, nao o endereço.
        int moves = (*pointsX.rbegin() + *pointsY.rbegin() + abs(*pointsX.begin()) + abs(*pointsY.begin())) * 2;
        // Pegamos o primeiro com begin e o ultimo com rbegin, pois o set ordena sozinho.
        cout << moves << endl;
    }
}