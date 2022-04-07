// AUTHOR: mitlex
// TITLE: Assignment 2 - Binary Search Trees & Sorting
// DATE: 7th March 2022
// VERSION: v1
// DESCRIPTION: 
// 
// PART 1 - PRINTING WORDS IN ALPHABETICAL ORDER
// 
// This program reads in a text file of words and stores each word in a vector of strings.
// This vector is used to construct a binary search tree (BST) of Treenodes.
// Each Treenode in the BST contains a unique word from the text file with a counter of the number of times that unique word appeared in the text file (word
// occurrence frequency).
// The BST is printed in alphabetical order using in-order traversal.
// 
// PART 2 - PRINTING WORDS IN DESCENDING ORDER OF OCCURRENCE FREQUENCY:
//
// In order to sort each Treenode in the BST in descending order of word occurrence frequency, a quicksort algorithm was used. 
// This was accomplished as follows:
// 
// Whilst constructing the BST, the program generates a count of the number of Treenodes in the BST.
// This Treenode count is used as an array size to create an array of Treenodes.
// This array is then populated using in-order traversal of the BST, where each Treenode visited in the tree is placed in the array.
// The Quick Sort algorithm is then applied to the array of Treenodes, in doing so ordering the Treenodes in descending order of word occurrence frequency.
// Lastly, the array is printed descending from the last index to the first index, showing the words in descending order of their occurrence frequency.

#include<fstream>
#include<string>
#include<vector>
#include"bintreetemplate.h"

using namespace std;

// code provided as part of assignment
// reads in a text file, populates and returns a vector of strings
vector<string> readCharFile(string filePath) {
    ifstream in(filePath);
    char c;
    string w = "";
    vector<string> strings;
    if (!in.eof() && in.fail()) {
        cerr << "Error reading " << filePath << endl;
        return strings;
    }

    if (in.is_open()) {
        while (in.good()) {
            in.get(c);
            c = tolower(c);
            if (isalpha(c)) {
                w += c;
            }
            else if (isspace(c)) {
                if (w != "") {
                    strings.push_back(w);
                }
                w = "";
            }
        }
        if (w != "") {
            strings.push_back(w);
        }
    }
    in.close();
    return strings;
}

int main()
{
    // read in text file and place words in vector of strings
    vector<string> strings;
    string filename = "testfile.txt";
    strings = readCharFile(filename);

    // create binary search tree
    Bintree<string> binary_search_tree(strings);

    // print binary search tree using in order traversal
    cout << "Words ordered alphabetically: " << endl << endl;
    cout << binary_search_tree;

    // print binary search tree with word frequencies in descending order
    cout << "Words in descending order of occurrence frequency: " << endl << endl;
    binary_search_tree.Quick_sort_binary_search_tree(binary_search_tree);

    return 0;
}
