#include "HashTable.h"    // Ensure the HashTable is included
#include "TextParser.h"  
#include "BenchmarkHashTable.h"
#include <chrono>
#include <iostream>
#include <vector>

void benchmark_insertion(HashTable& ht, const std::vector<std::string>& words) {
    // Start the clock
    auto start = std::chrono::high_resolution_clock::now();

    // Insert words into the hash table
    for (size_t i = 0; i < words.size(); ++i) {
        ht.insert(words[i], i);
    }

    // Stop the clock
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time taken for insertion of " << words.size() << " words: "
        << elapsed.count() << " seconds\n";
}

void benchmark_lookup(HashTable& ht, const std::vector<std::string>& words) {
    // Start the clock
    auto start = std::chrono::high_resolution_clock::now();

    // Lookup each word in the hash table
    for (const auto& word : words) {
        try {
            ht.get(word);
        }
        catch (const std::runtime_error& e) {
            // Ignore exceptions for words not found
        }
    }

    // Stop the clock
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time taken for lookups of " << words.size() << " words: "
        << elapsed.count() << " seconds\n";
}

void benchmark_removal(HashTable& ht, const std::vector<std::string>& words) {
    // Start the clock
    auto start = std::chrono::high_resolution_clock::now();

    // Remove each word from the hash table
    //int i = 0;
    for (const auto& word : words) {
        //std::cout << "\nWord :" << word << "Nr :" << i;
        //i++;
        try {
            int value = ht.get(word); // Only try remove words if they are found
            ht.remove(word);
        }
        catch (const std::runtime_error& e) {
            // Ignore exceptions for words not found
        }
    }

    // Stop the clock
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time taken for removal of " << words.size() << " words: "
        << elapsed.count() << " seconds\n";
}
