#include "map.hpp"
#include "msgassert.hpp"
#include <algorithm>

using std::endl;

/// @brief Lê K mesas
/// @param _istream, arquivo de entrada
/// @return vetor com as mesas
vector<pair<int, int>> readTables(istream &_istream = cin) {
    int k;
    _istream >> k;

    const int MAX_TABLES = 1e6;
    assert(k > 0, "A vovó possui um número negativo de mesas: " << k);
    assert(k <= MAX_TABLES, "A vovó possui muitas mesas: " << k);

    vector<pair<int, int>> tables(k);

    for (int i = 0; i < k; ++i) {
        // Eu não vou conferir a restrição de tamanho para as mesas
        _istream >> tables[i].first >> tables[i].second;
    }

    return tables;
}

int main() {
    Map house;
    vector<pair<int, int>> tables;

    // Leitura da entrada
    house.readMap();
    tables = readTables();

    // Ordena mesas
    sort(tables.begin(), tables.end(),
         [](const pair<int, int> &x, const pair<int, int> &y) {
             if (x.first * x.second > y.first * y.second) {
                 return true;
             }
             if ((x.first * x.second == y.first * y.second) &&
                 x.second > y.second) {
                 return true;
             }
             return false;
         });

    pair<int, int> maxTable;

    // Busca a maior mesa
    maxTable = house.findMaxTable(tables);
    assert(maxTable != INVALID_PAIR, "Nenhuma mesa cabe no mapa!");
    cout << maxTable.first << ' ' << maxTable.second << endl;

    return 0;
}
