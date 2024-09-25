#include "HashTable.h"
#include <stdexcept>
#include <iostream>

// TODO: Define the fixed size of the hash table (a prime number like 10007 to help with hash distribution).
const int TABLE_SIZE = 10007;

// TODO: Constructor - Initialize the hash table with an array and set default values for all entries.
HashTable::HashTable() {
    // TODO: Initialize table, insertionOrder, and tracking variables.
}

// TODO: Destructor - Clean up any allocated memory.
HashTable::~HashTable() {
    // TODO: Clean up dynamic memory if any is used.
}

// TODO: Implement the hash function that converts a string to an index using a polynomial rolling hash or similar technique.
int HashTable::hash(const std::string& key) {
    // TODO: Compute and return hash value.
    return 0; // Placeholder
}

// TODO: Implement the insert method with linear probing to handle collisions.
void HashTable::insert(const std::string& key, int value) {
    // TODO: Insert key-value pair using linear probing to resolve collisions.
}

// TODO: Implement the remove method to delete a key-value pair from the hash table using linear probing.
void HashTable::remove(const std::string& key) {
    // TODO: Remove the entry by marking it inactive.
}

// TODO: Implement the get method to retrieve a value for a given key with O(1) complexity.
int HashTable::get(const std::string& key) {
    // TODO: Retrieve the value for the key.
    return 0; // Placeholder
}

// TODO: Implement the get_last method to return the most recently inserted or updated key-value pair.
std::pair<std::string, int> HashTable::get_last() {
    // TODO: Return the last inserted key-value pair.
    return { "", 0 }; // Placeholder
}

// TODO: Implement the get_first method to return the least recently inserted or updated key-value pair.
std::pair<std::string, int> HashTable::get_first() {
    // TODO: Return the first inserted key-value pair.
    return { "", 0 }; // Placeholder
}
