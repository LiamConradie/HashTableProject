#include "HashTable.h"
#include "TextParser.h"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

int main() {
    // Initialize the hash table with a large prime number as the capacity to reduce collisions
    HashTable hashTable(200003); // 21013 is chosen for better hash distribution

    // Step 1: Parse the text file into a vector of words
    std::vector<std::string> words;
    parseTextFile("98-0.txt", words); // Parse words from the provided text file (A Tale of Two Cities)

    // Step 2: Insert words into the hash table while measuring insertion time
    auto start_insert = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < words.size(); ++i) {
        hashTable.insert(words[i], i + 1); // Insert each word with a value (index + 1)
    }
    auto end_insert = std::chrono::high_resolution_clock::now();

    // Output total collisions and time taken for insertion
    std::cout << "Total number of collisions during insertions: " << hashTable.get_collision_count() << std::endl;
    std::chrono::duration<double> insert_duration = end_insert - start_insert;
    std::cout << "Time taken to insert " << words.size() << " words: " << insert_duration.count() << " seconds." << std::endl;

    // Step 3: Test hash table's 'get' operation for specific words and measure the retrieval time

    // Test retrieving the value for the word "the"
    auto start_get = std::chrono::high_resolution_clock::now();
    std::cout << "Value for 'the': " << *hashTable.get("the") << std::endl;
    auto end_get = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> get_duration = end_get - start_get;
    std::cout << "Time taken to get 'the': " << get_duration.count() << " seconds." << std::endl;

    // Test retrieving the value for the word "and"
    start_get = std::chrono::high_resolution_clock::now();
    std::cout << "Value for 'and': " << *hashTable.get("and") << std::endl;
    end_get = std::chrono::high_resolution_clock::now();
    get_duration = end_get - start_get;
    std::cout << "Time taken to get 'and': " << get_duration.count() << " seconds." << std::endl;

    // Step 4: Test hash table's 'remove' operation and measure the removal time

    // Remove the word "the" from the hash table and measure time
    auto start_remove = std::chrono::high_resolution_clock::now();
    hashTable.remove("the");
    auto end_remove = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> remove_duration = end_remove - start_remove;
    std::cout << "Time taken to remove 'the': " << remove_duration.count() << " seconds." << std::endl;

    // Step 5: Test retrieval of the first and last inserted key-value pairs and measure time

    // Measure time to get the last inserted or updated element
    auto start_last = std::chrono::high_resolution_clock::now();
    auto last = hashTable.get_last();
    auto end_last = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> last_duration = end_last - start_last;

    // Output last inserted key-value pair if available
    if (last) {
        std::cout << "Last inserted key: " << last->first << ", value: " << last->second << std::endl;
    }
    std::cout << "Time taken to get the last inserted key: " << last_duration.count() << " seconds." << std::endl;

    // Measure time to get the first inserted or updated element
    auto start_first = std::chrono::high_resolution_clock::now();
    auto first = hashTable.get_first();
    auto end_first = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> first_duration = end_first - start_first;

    // Output first inserted key-value pair if available
    if (first) {
        std::cout << "First inserted key: " << first->first << ", value: " << first->second << std::endl;
    }
    std::cout << "Time taken to get the first inserted key: " << first_duration.count() << " seconds." << std::endl;

    return 0;
}
