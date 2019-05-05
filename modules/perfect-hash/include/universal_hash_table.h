#include <vector>
#include <list>
#include <random>
#include <ctime>
#include <iostream>

using uint = unsigned int;

#ifndef MODULES_PERFECT_HASH_INCLUDE_UNIVERSAL_HASH_TABLE_H_
#define MODULES_PERFECT_HASH_INCLUDE_UNIVERSAL_HASH_TABLE_H_

class unihash {
 private:
    uint prime = -1;
    uint alpha = -1;
    uint betta = -1;

    uint table_size;

    std::vector<bool> is_in_table;
    std::vector<int> table;

    static std::mt19937 gen;
    static std::uniform_int_distribution<uint> random;

 public:
    explicit unihash(uint _table_size);

    uint hash(int key);
    void rehash();

    uint add(int item);
    int find(int item);
    int getCell(int cell_number);
    void buildTable(std::vector<int> data);

    uint getAlpha() { return alpha; }
    uint getBetta() { return betta; }
    uint getSize() { return table_size; }

    std::mt19937 getGen() { return gen; }
    std::uniform_int_distribution<uint> getRandom() { return random; }
};

#endif  // MODULES_PERFECT_HASH_INCLUDE_UNIVERSAL_HASH_TABLE_H_