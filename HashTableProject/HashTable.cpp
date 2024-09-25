#include "HashTable.h"
#include <stdexcept>
#include <iostream>

// TODO: Define the fixed size of the hash table (a prime number like 10007 to help with hash distribution).
const int TABLE_SIZE = 10007;

// TODO: Constructor - Initialize the hash table with an array and set default values for all entries.
HashTable::HashTable() {
    // TODO: Initialize table, insertionOrder, and tracking variables.
    table = new Entry[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i].isActive = false;  // Mark all entries as inactive initially
    }
    size = 0;
    lastInsertedIndex = -1;
}

// TODO: Destructor - Clean up any allocated memory.
HashTable::~HashTable() {
    // TODO: Clean up dynamic memory if any is used.
    delete[] table;
}

// TODO: Implement the hash function that converts a string to an index using a polynomial rolling hash or similar technique.
int HashTable::hash(const std::string& key) {
    // TODO: Compute and return hash value.
    const int p = 31;  // A prime multiplier
    long long hash_value = 0, p_pow = 1;
    for (char c : key) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % TABLE_SIZE;
        p_pow = (p_pow * p) % TABLE_SIZE;
    }
    return static_cast<int>(hash_value);
}

// TODO: Implement the insert method with linear probing to handle collisions.
void HashTable::insert(const std::string& key, int value) {
    int idx = hash(key);
    int originalIdx = idx;

    // Use linear probing to resolve collisions
    while (table[idx].isActive && table[idx].key != key) {
        idx = (idx + 1) % TABLE_SIZE;  // Move to the next index
        if (idx == originalIdx) {
            throw std::overflow_error("Hash table is full");
        }
    }

    if (!table[idx].isActive || table[idx].key == key) {
        table[idx].key = key;
        table[idx].value = value;
        table[idx].isActive = true;

        // If this is a new entry (not an update)
        if (!table[idx].isActive || table[idx].key == key) {
            insertionOrder.push_back(idx);  // Track insertion order
        }

        lastInsertedIndex = idx;
        size++;
    }
}


// TODO: Implement the remove method to delete a key-value pair from the hash table using linear probing.
void HashTable::remove(const std::string& key) {
    // TODO: Remove the entry by marking it inactive.
    int idx = hash(key);
    int originalIdx = idx;

    // Use linear probing to find the key
    while (table[idx].isActive) {
        if (table[idx].key == key) {
            table[idx].isActive = false;  // Mark the entry as inactive
            size--;
            return;
        }
        idx = (idx + 1) % TABLE_SIZE;
        if (idx == originalIdx) {
            break;
        }
    }
    throw std::runtime_error("Key not found");
}

// TODO: Implement the get method to retrieve a value for a given key with O(1) complexity.
int HashTable::get(const std::string& key) {
    // TODO: Retrieve the value for the key.
    int idx = hash(key);
    int originalIdx = idx;

    // Use linear probing to find the key
    while (table[idx].isActive) {
        if (table[idx].key == key) {
            return table[idx].value;
        }
        idx = (idx + 1) % TABLE_SIZE;
        if (idx == originalIdx) {
            break;
        }
    }
    throw std::runtime_error("Key not found");
}

// TODO: Implement the get_last method to return the most recently inserted or updated key-value pair.
std::pair<std::string, int> HashTable::get_last() {
    // TODO: Return the last inserted key-value pair.
    if (lastInsertedIndex != -1 && table[lastInsertedIndex].isActive) {
        return { table[lastInsertedIndex].key, table[lastInsertedIndex].value };
    }
    throw std::runtime_error("No entries in hash table");
}

// TODO: Implement the get_first method to return the least recently inserted or updated key-value pair.
std::pair<std::string, int> HashTable::get_first() {
    // TODO: Return the first inserted key-value pair.
    if (!insertionOrder.empty()) {
        int idx = insertionOrder.front();  // Get the index of the first inserted item
        if (table[idx].isActive) {
            return { table[idx].key, table[idx].value };
        }
    }
    throw std::runtime_error("No entries in hash table");
}
