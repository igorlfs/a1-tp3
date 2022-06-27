#pragma once

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::pair;
using std::vector;

static constexpr pair<int, int> INVALID_PAIR = {-1, -1};
static constexpr char EMPTY = '.';

class Map {
  public:
    /// @brief Lê o mapa da entrada
    /// @param _istream, arquivo de entrada
    void readMap(istream &_istream = cin);

    /// @brief Imprime o mapa na saída
    /// @param _ostream, arquivo de saída
    void printMap(ostream &_ostream = cout) const;

    /// @brief Procura a maior mesa que cabe no mapa
    /// @param tables, vetor com os tamanhos das mesas
    pair<int, int> findMaxTable(vector<pair<int, int>> &tables) const;

    /// @brief verifica se uma mesa cabe na região que começa em (i,j)
    /// @param table, par (comprimento,largura) com o tamanho da mesa
    /// @param m, abscissa inicial
    /// @param n, ordenada inicial
    bool findMaxTableHelper(const pair<int, int> &table, const int &m,
                            const int &n) const;

  private:
    int length;
    int width;

    vector<vector<char>> house;
};
