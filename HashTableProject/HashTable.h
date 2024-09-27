#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <optional>
#include <utility>
#include <memory>

struct HashEntry {
    std::string key;
    int value;
    bool is_deleted;

    HashEntry(std::string k, int v);
};

class HashTable {
private:
    std::vector<std::unique_ptr<HashEntry>> table;
    size_t size;
    size_t capacity;
    int last_inserted_index;
    int first_inserted_index;
    size_t current_insert_count;

    size_t hash_function(const std::string& key);
    size_t find_key(const std::string& key);

public:
    HashTable(size_t cap);
    void insert(const std::string& key, int value);
    void remove(const std::string& key);
    std::unique_ptr<int> get(const std::string& key);
    std::unique_ptr<std::pair<std::string, int>> get_last();
    std::unique_ptr<std::pair<std::string, int>> get_first();
};

#endif // HASHTABLE_H
