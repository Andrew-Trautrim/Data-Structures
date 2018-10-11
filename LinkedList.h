/*
 * Complexity:
 * Access:      O(n)    Θ(n)
 * Search:      O(n)    Θ(n)
 * Insertion:   O(1)    Θ(1) 
 * Deletion:    O(1)    Θ(1)
 * Space:       O(n)
 */

/* 
 * File:   LinkedList.h
 * Author: Andrew-Trautrim
 *
 * Created on September 18, 2018, 10:37 AM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

struct lNode {
    int key;
    lNode* next;
};

// initiates root lNode to NULL;
static lNode* lRoot = NULL;

class LinkedList {
public:
    
    bool deleteValue(int value);
    bool insert(int value);
    bool insertAt(int location);
    
    int searchMax();
    int searchMin();
    
    lNode* search(int value);
    
    void remove();
    
private:
    
    lNode* lastNode;
    
    lNode* newNode(int value);
    
    void remove(lNode* n);
    
};

#endif /* LINKEDLIST_H */

