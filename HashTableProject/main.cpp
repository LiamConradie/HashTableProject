#include "HashTable.h"
#include "TextParser.h"
#include <vector>
#include <iostream>

int main() {
    HashTable ht;
    std::vector<std::string> words;

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
