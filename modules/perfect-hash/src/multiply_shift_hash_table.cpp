// Copyright 2019 Kutovoi Vadim

#include <vector>
#include <climits>

#include "../include/multiply_shift_hash_table.h"


std::mt19937 mshifthash::gen(time(0));
std::uniform_int_distribution<hashTable::ullong>
                mshifthash::random(0, ULLONG_MAX);

mshifthash::mshifthash()
{
}

mshifthash::mshifthash(ullong _table_size = 0) :
    one(1), w(64), M(std::log2(_table_size)) {
    table_size = _table_size;
    rehash();
}

hashTable::ullong mshifthash::hash(ullong key) {
    if (M == 0) return 0;
    return (alpha * key + betta) >> (w - M);
}

void mshifthash::rehash() {
    alpha = random(gen) % (one << (w - 1));
    if ((alpha % 2) == 0) ++alpha;
    betta = random(gen) % (one << (w - M - 1));

    std::vector<bool> tmp_vec(table_size, false);
    is_in_table = tmp_vec;

    std::vector<ullong> tmp_table(table_size, 0);
    table = tmp_table;
}
