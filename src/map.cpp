#include "map.hpp"

using std::swap;

void Map::readMap(istream &_istream) {
    _istream >> this->length >> this->width;

    this->house.resize(this->length);

    for (int i = 0; i < this->length; ++i) {

        this->house[i].resize(this->width);

        for (int j = 0; j < this->width; ++j) {
            _istream >> this->house[i][j];
        }
    }
}

void Map::printMap(ostream &_ostream) const {
    for (int i = 0; i < this->length; ++i) {
        for (int j = 0; j < this->width; ++j) {
            _ostream << this->house[i][j];
        }
        _ostream << '\n';
    }
}

pair<int, int> Map::findMaxTable(vector<pair<int, int>> &tables) const {
    for (pair<int, int> &table : tables) {
        bool swapped = false;
    trySwapping:
        for (int i = 1; i <= this->length; ++i) {
            if (table.first + i >= this->length) {
                continue;
            }
            for (int j = 1; j <= this->width; ++j) {
                if (table.second + j >= this->width) {
                    continue;
                }
                if (findMaxTableHelper(table, i, j)) {
                    if (swapped) {
                        return {table.second, table.first};
                    }
                    return {table.first, table.second};
                };
            }
        }
        // Rotaciona mesa se necessário
        if (!swapped) {
            swap(table.first, table.second);
            swapped = true;
            goto trySwapping;
        }
    }
    // Não deve chegar aqui
    return INVALID_PAIR;
}

bool Map::findMaxTableHelper(const pair<int, int> &table, const int &i,
                             const int &j) const {
    for (int ii = i; ii < i + table.first; ++ii) {
        for (int jj = j; jj < j + table.second; ++jj) {
            if (this->house[ii][jj] != EMPTY) {
                return false;
            }
        }
    }
    return true;
}
