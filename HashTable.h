/* 
 * Complexity:
 * Access:      N/A     N/A
 * Search:      O(n)    Θ(1)
 * Insertion:   O(n)    Θ(1) 
 * Deletion:    O(n)    Θ(1)
 * Space:       O(n)
 */

/* 
 * File:   HashTable.h
 * Author: Andrew-Trautrim
 *
 * Created on September 16, 2018, 2:32 PM
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

const int HASH_SIZE = 1000;

struct hNode {
    string value;
    hNode* next;
};

// creates hash table, set to NULL
static hNode* hTable[HASH_SIZE] = {NULL};

class HashTable {
public:
    
    bool deleteValue(string value);
    bool insert(string value);
    bool search(string value);
    
    void remove();
    
private:
    
    int size;
    string longest;
    
    hNode* newNode();
    
    unsigned int hash(string value);
    
    string toLowerCase(string s);
    
    void removeNode(hNode* n);
};

#endif /* HASHTABLE_H */

