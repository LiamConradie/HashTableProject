#include "HashTable.h"
#include <iostream>
#include <functional> // for std::hash

// HashEntry Constructor
HashEntry::HashEntry(std::string k, int v) : key(k), value(v), is_deleted(false) {}

// HashTable Constructor
HashTable::HashTable(size_t cap) : size(0), capacity(cap), last_inserted_index(-1), first_inserted_index(-1), current_insert_count(0) {
    table.resize(capacity);
}

// Hash Function (std::hash)
size_t HashTable::hash_function(const std::string& key) {
    return std::hash<std::string>{}(key) % capacity;
}

// Linear Probing to Find Key Index
size_t HashTable::find_key(const std::string& key) {
    size_t index = hash_function(key);
    size_t original_index = index;

    while (table[index] && (table[index]->key != key || table[index]->is_deleted)) {
        index = (index + 1) % capacity;
        if (index == original_index) break; // Full cycle, key not found
    }
    return index;
}

// Insert or Update Key-Value Pair
void HashTable::insert(const std::string& key, int value) {
    size_t index = find_key(key);

    if (!table[index] || table[index]->is_deleted) { // New insertion
        if (size == 0) {
            first_inserted_index = index; // First element tracking
        }
        table[index] = std::make_unique<HashEntry>(key, value); // Use unique_ptr
        size++;
    }
    else { // Key exists, update value
        table[index]->value = value;
    }

    table[index]->is_deleted = false;
    last_inserted_index = index; // Update last inserted tracking
    current_insert_count++;
}

// Remove Key-Value Pair
void HashTable::remove(const std::string& key) {
    size_t index = find_key(key);
    if (table[index] && !table[index]->is_deleted) {
        table[index]->is_deleted = true;
        size--;
    }
}

// Get Value for Key
std::unique_ptr<int> HashTable::get(const std::string& key) {
    size_t index = find_key(key);
    if (table[index] && !table[index]->is_deleted) {
        return std::make_unique<int>(table[index]->value);
    }
    return nullptr;
}

// Get Most Recently Inserted Key-Value Pair
std::unique_ptr<std::pair<std::string, int>> HashTable::get_last() {
    if (last_inserted_index == -1 || table[last_inserted_index]->is_deleted) {
        return nullptr;
    }
    return std::make_unique<std::pair<std::string, int>>(table[last_inserted_index]->key, table[last_inserted_index]->value);
}

// Get First Inserted Key-Value Pair
std::unique_ptr<std::pair<std::string, int>> HashTable::get_first() {
    if (first_inserted_index == -1 || table[first_inserted_index]->is_deleted) {
        return nullptr;
    }
    return std::make_unique<std::pair<std::string, int>>(table[first_inserted_index]->key, table[first_inserted_index]->value);
}
