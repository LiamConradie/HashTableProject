# HashTableProject
Part 1: Data Structures and Algorithms

See Solution_Overview.pdf for design comments.

This project implements a hash table using linear probing for collision resolution. It reads a text file, extracts words, and stores them in a fixed-size hash table. The project also supports operations like insertion, removal, lookup, and retrieval of the first and last inserted items in the hash table.

## Features

- **Hash Table Implementation**: Efficient hash table with linear probing for collision handling.
- **Text Parsing**: Extracts words from a text file, processes them, and inserts them into the hash table.
- **Operations**: Supports key hash table operations:
  - Insert a key-value pair.
  - Remove a key.
  - Get the value of a key.
  - Retrieve the first and last inserted keys.

## Requirements

- Visual Studio 2022 or later
- C++17 or higher
- Windows OS

## Files

- `HashTable.cpp` - Contains the implementation of the hash table data structure.
- `HashTable.h` - The header file that defines the `HashTable` class and its member functions.
- `TextParser.cpp` - Implements functions to parse a text file and extract words.
- `TextParser.h` - The header file that defines the `TextParser` class and its member functions.
- `main.cpp` - The main driver file that demonstrates the usage of the hash table and performs various operations (insert, remove, lookup, etc.).

## Installation and Usage

### Prerequisites

1. **Visual Studio 2022**:
   - Ensure that Visual Studio 2022 is installed on your machine.
   - You need to install the C++ development tools as part of Visual Studio.

2. **Cloning the Project**:
   - Clone the project files into your desired location using Git or download the source files manually.

### Build Instructions

1. Open the project folder in **Visual Studio 2022**.
2. Go to `File -> Open -> Folder` and select the project directory.
3. In Visual Studio, go to `Solution Explorer`, right-click on the solution, and choose **Build Solution** to compile the project.
4. Once the build is successful, the program will be ready to run.

### Running the Program

1. Ensure that the text file (`98-0.txt`) from Project Gutenberg's "A Tale of Two Cities" is placed in the project directory.
2. Run the project from Visual Studio by clicking on **Start (F5)**.
3. The program will parse the text file, insert the words into the hash table, and then perform various hash table operations like insertion, lookup, and removal.
4. The console will output statistics on collisions, time taken for various operations, and the retrieved values from the hash table.

## Key Operations

- **Insert**: Inserts words into the hash table with their corresponding index values.
- **Get**: Retrieves the value associated with a specific word (key).
- **Remove**: Deletes a word from the hash table.
- **Get First and Last**: Retrieves the first and last inserted key-value pairs from the hash table.

## Performance

- The hash table was tested with 141,633 words from "A Tale of Two Cities."
- The program efficiently handles collisions (699 collisions observed).
- The average time complexity for insertions, lookups, and deletions is **O(1)**.

## Example Output
```
Total number of collisions during insertions: 699 
Time taken to insert 141633 words: 0.0918875 seconds. 
Value for 'the': 141608 Time taken to get 'the': 0.0002807 seconds. 
Time taken to remove 'the': 5.5e-06 seconds. 
Last inserted key: ebooks, value: 141633 
Time taken to get the last inserted key: 4.7e-06 seconds. 
First inserted key: the, value: 141608 
Time taken to get the first inserted key: 4.3e-06 seconds.
```
