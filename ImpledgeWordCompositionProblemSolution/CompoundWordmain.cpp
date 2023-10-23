#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Defining a structure for Trie nodes
struct TrieNode {
    TrieNode* children[26]; // An array to store child nodes for each character
    bool isEndOfWord;      // Flag to mark the end of a valid word

    // Checking if the node has a child with character 'ch'
    bool hasChildren(char ch) {
        return children[ch - 'a'] != NULL;
    }

    // Get the child node with character 'ch'
    TrieNode* getChild(char ch) {
        return children[ch - 'a'];
    }

    void insert(char ch, TrieNode* childNode) {
        children[ch - 'a'] = childNode;
    }

    // Check if the current node marks the end of a word
    bool isEnd() {
        return isEndOfWord;
    }

    // Set the current node as the end of a word
    void setEnd() {
        isEndOfWord = true;
    }

    // Unset the current node as the end of a word
    void unsetEnd() {
        isEndOfWord = false;
    }
};

// Defining a class for finding the longest compound words
class CompoundWordFinder {
    TrieNode* root;

public:
    CompoundWordFinder() {
        root = new TrieNode();
    }

    // Comparator for sorting words based on length
    static bool wordComparator(string a, string b) {
        if (a.length() == b.length()) {
            return a < b;
        }
        return a.length() > b.length();
    }

    // Insert a word into the Trie data structure
    void insertWord(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->hasChildren(word[i])) {
                node->insert(word[i], new TrieNode());
            }
            node = node->getChild(word[i]);
        }
        node->setEnd();
    }

    // Recursively reset the end flag of Trie nodes for a given word
    void resetFlag(string str, int index, TrieNode* tempNode) {
        if (index == str.length()) {
            tempNode->unsetEnd();
            return;
        }
        resetFlag(str, index + 1, tempNode->getChild(str[index]));
    }

    // Recursively checking if a given word is a compound word
    bool isCompound(string str, int index, TrieNode* tempNode) {
        if (index == str.length()) {
            return tempNode->isEnd();
        }
        if (tempNode->isEnd()) {
            if (isCompound(str, index, root)) {
                return true;
            }
        }
        if (tempNode->hasChildren(str[index])) {
            return isCompound(str, index + 1, tempNode->getChild(str[index]));
        }
        else {
            return false;
        }
    }

    // Find and display the longest and second-longest compound words
    void findLongestCompoundWords(vector<string>& words) {
        vector<string> result;
        for (int i = 0; i < words.size(); i++) {
            result.push_back(words[i]);
            insertWord(words[i]);
        }
        sort(result.begin(), result.end(), wordComparator);
        string longestCompound = "", secondLongestCompound = "";
        for (int i = 0; i < result.size(); i++) {
            resetFlag(result[i], 0, root);
            if (isCompound(result[i], 0, root)) {
                if (longestCompound.empty()) {
                    longestCompound = result[i];
                }
                else {
                    secondLongestCompound = result[i];
                    break;
                }
            }
            insertWord(result[i]);
        }
        cout << "Longest Compound Word: " << longestCompound << endl;
        cout << "Second Longest Compound Word: " << secondLongestCompound << endl;
    }
};

int main() {
    CompoundWordFinder finder;
    fstream file;
    vector<string> wordList;
    file.open("Input_02.txt", ios::in);
    if (file.fail()) {
        cout << "Failed to open the file.";
    }
    else {
        string word;
        while (file >> word) {
            wordList.push_back(word);
        }
        file.close();

        auto startTime = high_resolution_clock::now();
        finder.findLongestCompoundWords(wordList);
        auto endTime = high_resolution_clock::now();
        auto elapsedTime = duration_cast<milliseconds>(endTime - startTime); // Calculate elapsed time
        cout << "Time taken to process the input file: " << elapsedTime.count() << " milliseconds" << endl;
    }
    return 0;
}


