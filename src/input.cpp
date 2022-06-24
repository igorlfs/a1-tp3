#include "input.hpp"
#include "msgassert.hpp"
#include <iostream>

using namespace std;

vector<pair<int, int>> Input::readTables(istream &_istream) {
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
