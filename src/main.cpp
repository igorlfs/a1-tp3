#include "input.hpp"
#include "map.hpp"
#include "msgassert.hpp"
#include <algorithm>

using std::endl;

int main() {
    Map house;
    vector<pair<int, int>> tables;

    // Leitura da entrada
    house.readMap();
    tables = Input::readTables();

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
