#include <bits/stdc++.h>
using namespace std;
using interval = pair<int, int>;
// Dado diversos intervalos, retorna a interseção máxima entre eles.
// Ex: cada intervalo representa o início e o fim de um espetáculo que acontecerá em determinado dia. Qual é o número máximo de espetáculos que acontecerão simultaneamete?
// Retorna vetor com o índice dos intervalos que estavam ativos simultâneamente(iniciando em 1). Com size, é possível obter a quantidade simultânea.
vector<int> max_intersection(const vector<interval> &is) {
    using event = pair<int, int>;
    vector<event> es;
    for (size_t i = 0; i < is.size(); ++i) {
        int a = is[i].first;
        int b = is[i].second;
        es.emplace_back(a, i + 1);    // Evento de início
        es.emplace_back(b, -(i + 1)); // Evento de fim
    }
    sort(es.begin(), es.end());
    set<int> active, max_set;
    for (const auto &e : es) {
        int i = e.second;
        if (i > 0)
            active.emplace(i);
        else
            active.erase(-i);
        if (active.size() >= max_set.size())
            max_set = active;
    }
    return {max_set.begin(), max_set.end()}; }
int main() {
    // Exemplo de intervalos
    vector<interval> intervals = {{2, 5}, {1, 6}, {5, 8}, {3, 7}, {4, 5}, {1, 4}, {4, 10}, {7, 9}};
    vector<int> result = max_intersection(intervals);
    for (const auto &r : result) {
        cout << r << endl; }
    return 0;
}