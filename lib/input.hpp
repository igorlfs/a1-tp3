#pragma once

#include <iostream>
#include <vector>

using std::cin;
using std::istream;
using std::pair;
using std::vector;

class Input {
  public:
    /// @brief Lê K mesas
    /// @param _istream, arquivo de entrada
    /// @return vetor com as mesas
    static vector<pair<int, int>> readTables(istream &_istream = cin);
};
