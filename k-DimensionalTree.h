/*
 * Complexity:
 * Access:      O(n)    Θ(log(n))
 * Search:      O(n)    Θ(log(n))
 * Insertion:   O(n)    Θ(log(n)) 
 * Deletion:    O(n)    Θ(log(n))
 * Space:       O(n)
 */

/* 
 * File:   k-DimensionalTree.h
 * Author: Andrew-Trautrim
 *
 * Created on September 20, 2018, 1:16 PM
 */

#ifndef K_DIMENSIONALTREE_H
#define K_DIMENSIONALTREE_H

#include <algorithm>
#include <cstdlib>

// default number of dimensions is 2
const static int K = 2;

struct kNode {
    int point[K];
    kNode *left, *right;
};

static kNode* kRoot = NULL;

class kDimensionalTree {
public:
    
    bool deleteValue(int value[]);
    bool insert(int value[]);
    bool search(int value[]);
    
    void remove();
    
private:
    
    bool compare(int arr1[], int arr2[]);
    
    kNode* newNode(int point[]);
    kNode* insert(kNode* n, int value[], unsigned int height);
    kNode* search(kNode* n, int value[], unsigned int height);
    
    void remove(kNode* n);
};

#endif /* K_DIMENSIONALTREE_H */

