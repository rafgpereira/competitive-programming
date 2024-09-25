#include <iostream>
#include <map>
#include <string>
using namespace std;

// CÓDIGO QUE EXPLORA O MAP
int main() {
    // Criação de um map que mapeia strings para inteiros
    map<string, int> myMap;
    // Inserindo elementos
    // Lembrando que o map ordena pela chave,
    // então ficará ordenado em ordem alfabética
    myMap["apple"] = 3;
    myMap["banana"] = 5;
    myMap["orange"] = 2;
    // Outra forma de inserir elementos
    myMap.insert({"grape", 4});
    //Incrementando o valor da chave banana
    myMap["banana"]++;
    // Acessando elementos (com verificação)
    cout << "Quantidade de bananas: " << myMap["banana"] << endl;
    // Procurando um elemento no map
    string key = "orange";
    // It é um ponteiro
    auto it = myMap.find(key);
    if (it != myMap.end())
        cout << key << " encontrado com valor: " << it->second << endl;
    else
        cout << key << " não encontrado" << endl;
    // Atualizando o valor de uma chave
    myMap["apple"] = 10;
    // Removendo um elemento
    myMap.erase("banana");
    // Percorrendo todos os elementos do map
    cout << "Elementos no map:" << endl;
    for (const auto &pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
    // Verificando o tamanho do map
    cout << "Tamanho do map: " << myMap.size() << endl;
    // Limpando o map
    myMap.clear();
    cout << "Map apos limpar, tamanho: " << myMap.size() << endl;
}
