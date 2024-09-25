#include "TextParser.h"
#include <fstream>
#include <cctype>
#include <string>
#include <vector>

// Function to parse the text file and extract words into a vector.
void parseTextFile(const std::string& filename, std::vector<std::string>& words) {
    std::ifstream infile(filename);
    std::string word;
    char ch;

    // Read the file character by character
    while (infile.get(ch)) {
        // Convert each alphabetic character to lowercase and build the word
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            word += std::tolower(static_cast<unsigned char>(ch));
        }
        else {
            // If a non-alphabetic character is encountered, treat it as a word boundary
            if (!word.empty()) {
                words.push_back(word); // Add the word to the vector
                word.clear();          // Clear the word to start fresh for the next one
            }
        }
    }

    // Make sure to add the last word if any
    if (!word.empty()) {
        words.push_back(word);
    }
}
