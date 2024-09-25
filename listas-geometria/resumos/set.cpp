#include <iostream>
#include <set>
using namespace std;
int main() {
    set<int> s;
    s.insert(5); s.insert(2); s.insert(8); s.insert(1); s.insert(10);
    cout << "Tamanho do set: " << s.size() << endl; // Saída: 5
    cout << "Elementos no set: ";
    for (int x : s) {
        cout << x << " "; // Saída: 1 2 5 8 10
    }
    if (!s.empty())
        cout << "Primeiro elemento: " << *s.begin() << endl; // Saída: 1
    if (!s.empty())
        cout << "Último elemento: " << *prev(s.end()) << endl; // Saída: 10
    // 7. Remover o primeiro elemento
    s.erase(s.begin());
    cout << "Set após remover o primeiro elemento: ";
    for (int x : s) {
        cout << x << " "; // Saída: 2 5 8 10
    }
    cout << endl;
    // 8. Remover o último elemento
    s.erase(prev(s.end()));
    cout << "Set após remover o último elemento: ";
    for (int x : s) {
        cout << x << " "; // Saída: 2 5 8
    }
    cout << endl;
    return 0;
}
