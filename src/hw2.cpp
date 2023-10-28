/// @author Gildardo (Quinn) Haro
/// @NSHE 5004465396
/// @brief Program that reads froms a file to determine the validity of each
/// LISP statement found in the file

#include "myStack.h"
#include "parenthesis.h"
#include <iostream>
#include <string>

template <class T>
binTreeNode<T>* create_tree(std::ifstream& infile);

template <class T>
void printPath(bool found_path, int targetSum, myStack<T>& path);

int main() {
    std::ifstream infile;   // source of LISP
    std::string file_name;  // LISP filename

    // User prompt
    std::cout << "Enter LISP file: ";
    std::cin >> file_name;
    std::cout << std::endl;

    infile.open(file_name);

    if (infile.is_open()) {
        int targetSum;
        // Grab Target Sum
        while(infile >> targetSum) {
            binTreeNode<int>* root = create_tree<int>(infile); // Start new tree
            myStack<int> path;              // holds the path just in case
            bool eval_flag = false;         // true if path exists
            
            eval_flag = evaluate(root, 0, targetSum, path);

            // Print path if it exists
            printPath(eval_flag, targetSum, path);
            destroyTree(root);              // Clean up;
            // myStack destructor automatically called for path
        }
    }
    else {
        std::cout << "File could not be opened\n";
    }
    return 0;
}

/// @brief Creates the root node for binary tree
/// @tparam T 
/// @param infile Source of the LISP statement
/// @return 
template <class T>
binTreeNode<T>* create_tree(std::ifstream& infile) {
    binTreeNode<T>* temp = nullptr; // Default to nullptr just in case
    char garbage;                   // To remove garbage value
    char value;                     // Grab the part we actually want
    
    // Step 1: Create the root
    // removes first parenthesis and grabs value if it exists
    infile >> garbage >> value;
    if (value != ')') {
        infile.putback(value);
        temp = new binTreeNode<T>;
        infile >> temp->item;
    }

    // Step 2: Make the rest of the tree
    // readLISP breaks if it doesn't start with a number or open
    // parenthesis
    infile >> garbage;
    if (garbage != ')') {
        infile.putback(garbage);
        readLISP(temp,infile);      // Genearte binary tree
    }

    // readLISP does not grab the last closing parentheis 
    infile >> garbage;
    if (garbage == ')') {
        infile.ignore();
    }

    return temp;
}

template <class T>
void printPath(bool found_path, int targetSum, myStack<T>& path) {
    if (found_path) {
        std::cout << "Path in tree exists\n";
        while (!path.isEmpty()) {
            std::cout << path.top() << ' ';

            path.pop();
            // Keep adding + unless we ran out of stuff
            if (path.isEmpty()) {
                std::cout << "= " << targetSum << "\n\n";
            }
            else {
                std::cout << "+ ";
            }
        }
    }
    else{
        std::cout << "No such path exists , LISP is a pain anyway\n\n";
    }
}