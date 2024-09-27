#include "HashTable.h"
#include <iostream>

// Constructor for HashEntry to initialize a key-value pair
HashEntry::HashEntry(std::string k, int v) : key(k), value(v), is_deleted(false) {}

// HashTable Constructor: Initializes the hash table with a given capacity
// Tracks first and last inserted indices and initializes the collision counter
HashTable::HashTable(size_t cap) : size(0), capacity(cap), last_inserted_index(-1), first_inserted_index(-1), current_insert_count(0) {
    table.resize(capacity); // Resize the hash table to the specified capacity
}

// Custom Hash Function (FNV-1a): Generates a hash for the given string
// This hash function ensures uniform distribution and minimizes collisions
size_t HashTable::hash_function(const std::string& key) {
    const size_t fnv_prime = 0x1000193;
    const size_t offset_basis = 0x811C9DC5;
    size_t hash = offset_basis;

    // Apply FNV-1a hash algorithm to each character in the key
    for (char c : key) {
        hash ^= static_cast<size_t>(c);
        hash *= fnv_prime;
    }

    // Return the hash value modulo the capacity to fit within the table
    return hash % capacity;
}

// Find the index for a key using linear probing
// If 'count_collisions' is true, increments the collision count during probing
size_t HashTable::find_key(const std::string& key, bool count_collisions) {
    size_t index = hash_function(key);
    size_t original_index = index;

    // Linear probing loop: continues until an empty or matching slot is found
    while (table[index] && (table[index]->key != key || table[index]->is_deleted)) {
        if (count_collisions) {
            collision_count++; // Count collisions when specified
        }
        index = (index + 1) % capacity; // Move to the next slot (wrap around)
        if (index == original_index) break; // Full cycle, stop if back to the start
    }
    return index;
}

// Insert a key-value pair into the hash table, or update the value if the key exists
void HashTable::insert(const std::string& key, int value) {
    if (key.empty()) {
        std::cerr << "Error: Cannot insert an empty key." << std::endl;
        return;
    }

    size_t index = hash_function(key);
    size_t original_index = index;
    bool collision_detected = false;

    // Linear probing to find the appropriate slot
    while (table[index] && !table[index]->is_deleted && table[index]->key != key) {
        if (!collision_detected) {
            collision_count++; // Increment collision count only once per insertion
            collision_detected = true;
        }
        index = (index + 1) % capacity; // Move to the next slot
        if (index == original_index) { // If table is full
            std::cerr << "Error: Hash table is full, cannot insert new key '" << key << "'." << std::endl;
            return;
        }
    }

    // New entry or update the existing entry
    if (!table[index] || table[index]->is_deleted) { // New insertion
        if (size == 0) {
            first_inserted_index = index; // Track first inserted element
        }
        table[index] = std::make_unique<HashEntry>(key, value); // Allocate new entry
        size++;
    }
    else { // Key exists, update value
        table[index]->value = value;
    }

    table[index]->is_deleted = false;
    last_inserted_index = index; // Update last inserted tracking
    current_insert_count++;
}

// Get the current number of collisions encountered
size_t HashTable::get_collision_count() const {
    return collision_count;
}

// Remove a key from the hash table (sets the 'is_deleted' flag to true)
void HashTable::remove(const std::string& key) {
    if (key.empty()) {
        std::cerr << "Error: Cannot remove an entry with an empty key." << std::endl;
        return;
    }

    size_t index = find_key(key);
    if (table[index] && !table[index]->is_deleted) {
        table[index]->is_deleted = true; // Mark as deleted
        size--;
    }
    else {
        std::cerr << "Error: Key '" << key << "' not found in the hash table." << std::endl;
    }
}

// Retrieve the value for a given key
// Returns a unique pointer to the value, or nullptr if the key is not found
std::unique_ptr<int> HashTable::get(const std::string& key) {
    if (size == 0) {
        std::cerr << "Error: Hash table is empty. No keys to get." << std::endl;
        return nullptr;
    }

    size_t index = find_key(key);
    if (table[index] && !table[index]->is_deleted) {
        return std::make_unique<int>(table[index]->value); // Return value if key is found
    }

    std::cerr << "Error: Key '" << key << "' not found in the hash table." << std::endl;
    return nullptr;
}

// Get the most recently inserted key-value pair
std::unique_ptr<std::pair<std::string, int>> HashTable::get_last() {
    if (size == 0 || last_inserted_index == -1) {
        std::cerr << "Error: Hash table is empty. No last inserted key available." << std::endl;
        return nullptr;
    }
    return std::make_unique<std::pair<std::string, int>>(table[last_inserted_index]->key, table[last_inserted_index]->value);
}

// Get the first inserted key-value pair
std::unique_ptr<std::pair<std::string, int>> HashTable::get_first() {
    if (size == 0 || first_inserted_index == -1) {
        std::cerr << "Error: Hash table is empty. No first inserted key available." << std::endl;
        return nullptr;
    }
    return std::make_unique<std::pair<std::string, int>>(table[first_inserted_index]->key, table[first_inserted_index]->value);
}
