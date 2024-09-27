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
    const size_t fnv_prime = 0x1000193;
    const size_t offset_basis = 0x811C9DC5;
    size_t hash = offset_basis;

    for (char c : key) {
        hash ^= static_cast<size_t>(c);
        hash *= fnv_prime;
    }

    return hash % capacity;
}

// Linear Probing to Find Key Index
size_t HashTable::find_key(const std::string& key, bool count_collisions) {
    size_t index = hash_function(key);
    size_t original_index = index;

    // Iterate using linear probing
    while (table[index] && (table[index]->key != key || table[index]->is_deleted)) {
        if (count_collisions) {
            // Count collisions if this option is enabled
            collision_count++;
        }
        index = (index + 1) % capacity;
        if (index == original_index) break; // Full cycle, key not found
    }
    return index;
}

// Insert or Update Key-Value Pair
void HashTable::insert(const std::string& key, int value) {
    if (key.empty()) {
        std::cerr << "Error: Cannot insert an empty key." << std::endl;
        return;
    }

    size_t index = hash_function(key);
    size_t original_index = index; // Save the original index for comparison

    // If the slot is not empty, we have a collision
    bool collision_detected = false;

    // Handle collisions with linear probing
    while (table[index] && !table[index]->is_deleted && table[index]->key != key) {
        if (!collision_detected) {
            // Count only the first time we detect a collision for this insert
            collision_count++;
            collision_detected = true;
        }
        index = (index + 1) % capacity;

        // If we loop back to the original index, the table is full
        if (index == original_index) {
            std::cerr << "Error: Hash table is full, cannot insert new key '" << key << "'." << std::endl;
            return;
        }
    }

    // Insert the new entry or update the existing one
    if (!table[index] || table[index]->is_deleted) { // New insertion
        if (size == 0) {
            first_inserted_index = index; // Track the first element
        }
        table[index] = std::make_unique<HashEntry>(key, value); // Use unique_ptr
        size++;
    }
    else { // Key exists, update the value
        table[index]->value = value;
    }

    table[index]->is_deleted = false;
    last_inserted_index = index; // Update last inserted tracking
    current_insert_count++;
}
// Return the collision count
size_t HashTable::get_collision_count() const {
    return collision_count;
}

// Remove Key-Value Pair
void HashTable::remove(const std::string& key) {
    if (key.empty()) {
        std::cerr << "Error: Cannot remove an entry with an empty key." << std::endl;
        return;
    }

    size_t index = find_key(key);
    if (table[index] && !table[index]->is_deleted) {
        table[index]->is_deleted = true;
        size--;
    }
    else {
        std::cerr << "Error: Key '" << key << "' not found in the hash table." << std::endl;
    }
}

// Get Value for Key
std::unique_ptr<int> HashTable::get(const std::string& key) {
    if (size == 0) {
        std::cerr << "Error: Hash table is empty. No keys to get." << std::endl;
        return nullptr;
    }

    size_t index = find_key(key);
    if (table[index] && !table[index]->is_deleted) {
        return std::make_unique<int>(table[index]->value);
    }

    std::cerr << "Error: Key '" << key << "' not found in the hash table." << std::endl;
    return nullptr;
}

// Get Most Recently Inserted Key-Value Pair
std::unique_ptr<std::pair<std::string, int>> HashTable::get_last() {
    if (size == 0 || last_inserted_index == -1) {
        std::cerr << "Error: Hash table is empty. No last inserted key available." << std::endl;
        return nullptr;
    }
    return std::make_unique<std::pair<std::string, int>>(table[last_inserted_index]->key, table[last_inserted_index]->value);
}

std::unique_ptr<std::pair<std::string, int>> HashTable::get_first() {
    if (size == 0 || first_inserted_index == -1) {
        std::cerr << "Error: Hash table is empty. No first inserted key available." << std::endl;
        return nullptr;
    }
    return std::make_unique<std::pair<std::string, int>>(table[first_inserted_index]->key, table[first_inserted_index]->value);
}
