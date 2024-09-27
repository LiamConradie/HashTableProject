#pragma once

#include <vector>
#include <string>

// Function to parse a text file and extract words
// The function reads the content of the file specified by 'filename',
// extracts words, and stores them in the provided 'words' vector.
//
// Parameters:
// - filename: The path to the text file that needs to be parsed.
// - words: A reference to a vector of strings, where the extracted words will be stored.
//
// The function processes the file character by character, identifying words by
// detecting sequences of alphabetic characters. Non-alphabetic characters are treated
// as word boundaries.
void parseTextFile(const std::string& filename, std::vector<std::string>& words);
