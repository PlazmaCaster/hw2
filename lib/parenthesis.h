/// @author: Gildardo (Quinn) Haro
/// @NSHE: 5004465396
/// @brief: The header file for LISP related functions. readLISP was given to us
/// by professor Lin. The rest were implemented by me

#include <fstream>
#include <iostream>
#include "myStack.h"

using namespace std;    // Polluting namespace :(

/// @brief Binary Tree Node Struct
/// @tparam type 
template <class type>
struct binTreeNode {
    type item;
    binTreeNode<type>* left;
    binTreeNode<type>* right;
};

/// @brief Reads in a LISP structure to generate binary tree
/// @note NOT MADE BY ME, given to us by professor Lin
/// @tparam type 
/// @param r Root to subtree
/// @param infile LISP Source
template <class type>
void readLISP(binTreeNode<type>* r, ifstream& infile) {
    binTreeNode<int>* tmp;
    char parenthesis;
    int value;

    //get
    infile >> parenthesis;
    if (parenthesis == '(') {
        // left
        infile >> parenthesis; //get right parenthesis, but
        // this parenthesis can be either an integer or a "("
        if (parenthesis != ')')	// if it is a digit, put value in tree
        {
            infile.putback(parenthesis);
            infile >> value;
            r->left = new binTreeNode<int>;
            tmp = r->left;
            tmp->item = value;
            readLISP(r->left, infile);
            infile >> parenthesis; // get right parenthesis
        }
        else {
            r->left = nullptr;
        }

        //right
        infile >> parenthesis; // get left parenthesis
        // cout << "parenthesis one " << parenthesis << endl;
        if (parenthesis == '(') {
            infile >> parenthesis; //get right parenthesis, but
            // cout << "parenthesis two " << parenthesis << endl;
            // cout << endl;
            if (parenthesis != ')')	// if it is a digit, put value in tree
            {
                infile.putback(parenthesis);
                infile >> value;
                r->right = new binTreeNode<int>;
                tmp = r->right;
                tmp->item = value;
                readLISP(r->right, infile);
                infile >> parenthesis; // get right parenthesis
            }
            else {
                r->right = nullptr;
            }
        }
    }
}

/// @brief Given a target sum, attempts to find a valid path from root to leaf node
/// such that the sum of each node's value equals the target sum.
/// @note Valid path is root to leaf ONLY. No stopping halfway
/// @tparam type (totally not an int)
/// @param r Pointer to the root of any subtree
/// @param runningSum the current running sum for specific path
/// @param targetSum the sum whose path we are looking for
/// @param path If a path is found, a stack that contains the path in reverse order
/// @return boolean: True if path is found, false otherwise
template <class type>
bool evaluate(binTreeNode<type>* r, int runningSum, int targetSum, myStack<type>& path) {
    if (r != nullptr) {
        // Always update running sum
        runningSum += r->item;

        // Only starts pushing to stack when at a leaf node
        if (r->left == nullptr && r->right == nullptr && runningSum == targetSum) {
            path.push(r->item);
            return true;
        }

        // Passes truth value up (left path)
        if (evaluate(r->left, runningSum, targetSum, path)) {
            path.push(r->item); 
            return true;
        } 
        
        // Passes truth value up (right path)
        if (evaluate(r->right, runningSum, targetSum, path)) {
            path.push(r->item);
            return true;
        }

        // Default to false 
        return false;
    }
    // Default to false (in case it hits a nullptr for safety)
    return false;
}

/// @brief Does a pre-order destruction of the tree
/// @tparam type (std::int)
/// @param r root to the subtree
template <class type>
void destroyTree(binTreeNode<type>* r) {
    // Pre-order destruction (comes with a free poster if you pre-order now)
    if (r != nullptr) {
        destroyTree(r->left);
        destroyTree(r->right);
        delete r;
    }
}