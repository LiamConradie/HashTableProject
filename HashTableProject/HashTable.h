#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <optional>
#include <utility>
#include <memory>

// Structure to represent an entry in the hash table
// Stores the key-value pair along with a flag indicating if the entry is deleted
struct HashEntry {
    std::string key;  // The key (word) being stored
    int value;        // The associated value (e.g., index or count)
    bool is_deleted;  // Flag to mark if the entry is deleted

    // Constructor to initialize a HashEntry with a key and a value
    HashEntry(std::string k, int v);
};

// HashTable class implementing a hash table with linear probing for collision resolution
class HashTable {
private:
    std::vector<std::unique_ptr<HashEntry>> table; // Vector of hash table entries (using smart pointers)
    size_t size;           // Current number of elements in the table
    size_t capacity;       // Maximum capacity of the hash table
    int last_inserted_index; // Index of the most recently inserted key-value pair
    int first_inserted_index; // Index of the first inserted key-value pair
    size_t current_insert_count; // Count of insert operations performed
    size_t collision_count;    // Count of collisions encountered during insertions

    // Hash function to convert a string (key) into an index in the hash table
    size_t hash_function(const std::string& key);

    // Finds the index of a given key in the table using linear probing
    // Optionally counts collisions during the search
    size_t find_key(const std::string& key, bool count_collisions = false);

public:
    // Constructor to initialize the hash table with a given capacity
    HashTable(size_t cap);

    // Inserts a key-value pair into the hash table
    // If the key already exists, updates its value
    void insert(const std::string& key, int value);

    // Removes a key-value pair from the hash table
    void remove(const std::string& key);

    // Retrieves the value associated with a given key
    // Returns a unique_ptr to the value, or nullptr if the key is not found
    std::unique_ptr<int> get(const std::string& key);

    // Retrieves the most recently inserted key-value pair
    std::unique_ptr<std::pair<std::string, int>> get_last();

    // Retrieves the first inserted key-value pair
    std::unique_ptr<std::pair<std::string, int>> get_first();

    // Returns the total number of collisions encountered during insertions
    size_t get_collision_count() const;
};

#endif // HASHTABLE_H
