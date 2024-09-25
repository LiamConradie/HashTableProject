#include "HashTable.h"
#include "TextParser.h"
#include <vector>
#include <iostream>
#include <cassert>

int main() {
    HashTable ht;
    std::vector<std::string> words;

    const int TABLE_SIZE = 10007;


    /*
    // Test 1: Hashing the same string should always give the same result
    std::string key = "hello";
    int hash1 = ht.hash(key);
    int hash2 = ht.hash(key);
    assert(hash1 == hash2);

    // Test 2: Hashing different strings should give different results
    std::string key2 = "world";
    int hash3 = ht.hash(key2);
    assert(hash1 != hash3);

    // Test 3: Check if the hash value is within the correct range
    assert(hash1 >= 0 && hash1 < TABLE_SIZE);
    assert(hash3 >= 0 && hash3 < TABLE_SIZE);

    // Test 4: Hash empty string
    std::string empty = "";
    int emptyHash = ht.hash(empty);
    assert(emptyHash >= 0 && emptyHash < TABLE_SIZE);

    // Test 5: Hash single character
    std::string singleChar = "a";
    int singleCharHash = ht.hash(singleChar);
    assert(singleCharHash >= 0 && singleCharHash < TABLE_SIZE);

    std::cout << "All tests passed!" << std::endl;
    */




    // TODO: Parse the book text file from Project Gutenberg and populate the 'words' vector.
    parseTextFile("98-0.txt", words);

    // TODO: Insert each word from the 'words' vector into the hash table with its position as the value.
    for (size_t i = 0; i < words.size(); ++i) {
        ht.insert(words[i], i);
    }

    // TODO: Test the hash table by performing inserts, gets, and removals.

    try {
        // TODO: Retrieve and print the most recently inserted or updated key-value pair.
        auto last = ht.get_last();
        std::cout << "Last inserted: " << last.first << " => " << last.second << std::endl;

        // TODO: Retrieve and print the least recently inserted or updated key-value pair.
        auto first = ht.get_first();
        std::cout << "First inserted: " << first.first << " => " << first.second << std::endl;

        // TODO: Retrieve and print the value for a specific key.
        int value = ht.get("london");  // Example key
        std::cout << "'london' found with value: " << value << std::endl;

        // TODO: Remove a key and test the behavior.
        ht.remove("london");
        value = ht.get("london");  // This should throw an exception or print an error.

    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
