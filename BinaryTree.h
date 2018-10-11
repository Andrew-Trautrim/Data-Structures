/* 
 * Complexity:
 * Access:      O(n)    Θ(log(n))
 * Search:      O(n)    Θ(log(n))
 * Insertion:   O(n)    Θ(log(n)) 
 * Deletion:    O(n)    Θ(log(n))
 * Space:       O(n)
 */

/* 
 * File:   BinaryTree.h
 * Author: Andrew-Trautrim
 *
 * Created on September 1, 2018, 12:20 PM
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <algorithm>
#include <cstdlib>

using namespace std;

struct bNode {
    int key;
    bNode *left, *right;
};

// initiates root bNode to NULL;
static bNode* bRoot = NULL;

class BinaryTree {
    
public:
    
    bNode* binarySearch(int value);
    
    bool deleteValue(int value);
    bool insert(int value);
    
    int longestBranch();
    int searchMax();
    int searchMin();
    
    void remove();
    
private:
    
    bNode* binarySearch(int value, bNode* n);
    bNode* insert(int value, bNode* n);
    bNode* newNode(int value);
    
    int longestBranch(bNode* n);
    int searchMax(bNode* n, int maxValue);
    int searchMin(bNode* n, int minValue);
    
    void remove(bNode* n);
 
};

#endif /* BINARYTREE_H */

