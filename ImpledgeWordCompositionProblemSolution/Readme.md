# Longest Compound Word Finder

## Overview
This C++ program solves the Word Composition Problem by finding the longest and second-longest compound words within a list of words provided in an input file. The program uses a Trie data structure to efficiently search for compound words.

## Execution Steps
1. Clone this repository to your local machine.
2. Open the project in your C++ development environment (e.g., Visual Studio).
3. Compile and run the `LongestCompoundWordMain.cpp` file (ensure you have a C++ compiler installed).
4. Input files must be in the same directory as the source code.
5. In the `LongestCompoundWordMain.cpp` file, update the input file name on line 127 to either `input_01.txt` or `input_02.txt`, based on your requirements.
6. Run the program, and it will display the output in the console.

## Approach
- The program starts by sorting the input words in ascending order based on their length using a custom comparator.
- It then iteratively identifies the longest compound word by removing the longest word from the sorted list and checking if it can be formed from other words in the list.
- The program repeats this process to find the second longest compound word.

## Implementation
- The core functionality of the program is encapsulated in a `LongestCompoundWordFinder` class.
- Input is read from the specified input file, and the program stores it in a vector.
- The `findLongestCompoundWords` function is used to identify the longest and second longest compound words.
- A Trie data structure is employed to efficiently manage and search for words.
- The program marks flags for words to track their usability in compound word formation.












