#pragma once

#include "HashTable.h" 
#include <vector>
#include <string>

void benchmark_insertion(HashTable& ht, const std::vector<std::string>& words);
void benchmark_lookup(HashTable& ht, const std::vector<std::string>& words);
void benchmark_removal(HashTable& ht, const std::vector<std::string>& words);
