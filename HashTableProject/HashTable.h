#pragma once
#include <string>
#include <vector>

class HashTable {
private:
    // TODO: Define a structure for storing key-value pairs and an "isActive" flag for handling deleted entries.

    // TODO: Define a fixed-sized hash table using an array of the above structure.

    // TODO: Define a vector to keep track of insertion order.

    // TODO: Define variables to track the last and first inserted or modified entries.

    // TODO: Implement a hash function that converts a string key to an index in the table.
    int hash(const std::string& key);

public:
    HashTable();   // Constructor
    ~HashTable();  // Destructor

    // TODO: Implement the insert method which inserts a new key-value pair or replaces the value if the key exists.
    void insert(const std::string& key, int value);

    // TODO: Implement the remove method which removes a key-value pair from the table.
    void remove(const std::string& key);

    // TODO: Implement the get method which retrieves the value for a given key.
    int get(const std::string& key);

    // TODO: Implement the get_last method which retrieves the most recently inserted or updated key-value pair.
    std::pair<std::string, int> get_last();

    // TODO: Implement the get_first method which retrieves the least recently inserted or updated key-value pair.
    std::pair<std::string, int> get_first();
};
