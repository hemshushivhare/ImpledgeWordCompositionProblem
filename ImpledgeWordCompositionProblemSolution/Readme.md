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
- I have made a class`LongestCompoundWordFinder` which contains all the functions required by the program.
- Input is read from the specified input file, and the program stores it in a vector.
- The `findLongestCompoundWords` function is used to identify the longest and second longest compound words.
- A Trie data structure is employed to efficiently manage and search for words.
- The program marks flags for words to track their usability in compound word formation.
  
## Time Complexity
The average time complexity of this solution can be approximated as O(N * L) in most practical cases, where N is the number of words in the input and L is the average length of the words.

## Code Execution Flow

   - The code begins by defining a Trie data structure for efficiently storing and managing words. It initializes the root of the Trie.

   - The program reads words from an input file ("Input_02.txt") and inserts them into the Trie data structure using the `insertWord` method. For each word, it traverses the Trie, creating nodes as needed to represent the word.

   - After inserting all the words into the Trie, it sorts the list of words based on their lengths and lexicographic order using the `wordComparator` and the `sort` function.

   - The program starts with an empty `result` vector and iterates through the sorted list of words. It adds each word to the `result` vector and checks if it's a compound word by using the Trie. To determine if a word is a compound word, it recursively checks if the word can be split into smaller words in the Trie.

   - The program identifies and displays the longest and second-longest compound words found during the iteration.
    
   - The code records the start time and end time of the Trie-based compound word finding process and calculates the elapsed time.

   - Finally, the program prints the longest and second-longest compound words it found, as well as the time taken to process the input file.














