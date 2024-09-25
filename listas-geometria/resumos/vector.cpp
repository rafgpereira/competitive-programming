#include <iostream>
#include <vector>
#include <algorithm> // Para funções como sort()
using namespace std;
bool compareDescending(int a, int b) {
    return a > b;
}
int main() {
    // 1. Declaração e Inicialização
    vector<int> v1;       // Vetor vazio
    vector<int> v2(5);   // Vetor de tamanho 5 com valores iniciais 0
    vector<int> v3(5, 10);// Vetor de tamanho 5 com valores iniciais 10
    vector<int> v4 = {1, 2, 3, 4, 5}; // Inicializado com lista de valores
    // 2. Adicionar Elementos no final
    v1.push_back(1); v1.push_back(2); v1.push_back(3);
    cout << "Tamanho de v1: " << v1.size() << endl;
    cout << "Elemento no índice 0 de v1: " << v1[0] << endl; // Acesso via operador []
    cout << "Elemento no índice 2 de v1: " << v1.at(2) << endl; // Acesso via at()
    cout << "Elementos de v1: ";
    for (int i = 0; i < v1.size(); ++i) {
        cout << v1[i] << " "; // Usando índice }
    cout << endl;
    cout << "Elementos de v3 (usando range-based for): ";
    for (int x : v3) {
        cout << x << " "; }
    // 6. Modificar o vetor
    v4[1] = 10; // Modifica o valor no índice 1
    v4.at(3) = 20; // Modifica o valor no índice 3 usando at()
    sort(v4.begin(), v4.end()); // Ordena v4
    sort(v4.begin(), v4.end(), compareDescending);// Ordem decrescente
    v1.pop_back(); // Remove o último elemento
    v4.erase(v4.begin() + 1); // Remove o elemento no índice 1
    v1.insert(v1.begin() + 1, 100); // Insere 100 na posição 1
    v2.clear(); // Remove todos os elementos de v2
    if (v2.empty())
        cout << "v2 está vazio!" << endl;
    cout << "Primeiro elemento de v4: " << v4.front() << endl;
    cout << "Último elemento de v4: " << v4.back() << endl;
}
