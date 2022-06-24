#include "input.hpp"
#include "map.hpp"
#include "msgassert.hpp"
#include <algorithm>

using std::endl;

int main() {
    Map m;
    vector<pair<int, int>> tables;

    // Leitura da entrada
    m.readMap();
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

    pair<int, int> p;

    // Busca a maior mesa
    p = m.findMaxTable(tables);
    assert(p != INVALID_PAIR, "Nenhuma mesa cabe no mapa!");
    cout << p.first << ' ' << p.second << endl;

    return 0;
}
