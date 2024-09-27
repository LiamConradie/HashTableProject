#include "HashTable.h"
#include "TextParser.h"
#include <iostream>
#include <vector>
#include <string>
#include <chrono> // For measuring time

int main() {
    // Use a large prime number for capacity to reduce collisions
    HashTable hashTable(21013); // A large prime number for capacity for good distribution

    // Step 2: Parse the words from the text file
    std::vector<std::string> words;
    parseTextFile("98-0.txt", words); // Parse words from "98-0.txt"

    // Step 3: Insert parsed words into the hash table with time measurement
    auto start_insert = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < words.size(); ++i) {
        hashTable.insert(words[i], i + 1); // Insert word with some dummy value (like index)
    }
    auto end_insert = std::chrono::high_resolution_clock::now();
    std::cout << "Total number of collisions during insertions: " << hashTable.get_collision_count() << std::endl;
    std::chrono::duration<double> insert_duration = end_insert - start_insert;
    std::cout << "Time taken to insert " << words.size() << " words: " << insert_duration.count() << " seconds." << std::endl;

    // Step 4: Test hash table functionalities with time measurement for 'get'
    auto start_get = std::chrono::high_resolution_clock::now();
    std::cout << "Value for 'the': " << *hashTable.get("the") << std::endl;
    auto end_get = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> get_duration = end_get - start_get;
    std::cout << "Time taken to get 'the': " << get_duration.count() << " seconds." << std::endl;

    // Test 'and'
    start_get = std::chrono::high_resolution_clock::now();
    std::cout << "Value for 'and': " << *hashTable.get("and") << std::endl;
    end_get = std::chrono::high_resolution_clock::now();
    get_duration = end_get - start_get;
    std::cout << "Time taken to get 'and': " << get_duration.count() << " seconds." << std::endl;

    // Remove a word and test the remove operation
    auto start_remove = std::chrono::high_resolution_clock::now();
    hashTable.remove("the");
    auto end_remove = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> remove_duration = end_remove - start_remove;
    std::cout << "Time taken to remove 'the': " << remove_duration.count() << " seconds." << std::endl;


    // Measure time to get the last and first inserted elements
    auto start_last = std::chrono::high_resolution_clock::now();
    auto last = hashTable.get_last();
    auto end_last = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> last_duration = end_last - start_last;

    if (last) {
        std::cout << "Last inserted key: " << last->first << ", value: " << last->second << std::endl;
    }
    std::cout << "Time taken to get the last inserted key: " << last_duration.count() << " seconds." << std::endl;

    auto start_first = std::chrono::high_resolution_clock::now();
    auto first = hashTable.get_first();
    auto end_first = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> first_duration = end_first - start_first;

    if (first) {
        std::cout << "First inserted key: " << first->first << ", value: " << first->second << std::endl;
    }
    std::cout << "Time taken to get the first inserted key: " << first_duration.count() << " seconds." << std::endl;

    return 0;
}
