/*
 * Complexity:
 * m = length of word
 * Access:      O(m)    Θ(m)
 * Search:      O(m)    Θ(m)
 * Insertion:   O(m)    Θ(m) 
 * Deletion:    O(m)    Θ(m)
 * Space:       O(n)
 */

/* 
 * File:   Trie.h
 * Author: Andrew-Trautrim
 *
 * Created on September 12, 2018, 6:18 PM
 */

#ifndef TRIE_H
#define TRIE_H

#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

const int ALPHABET_SIZE = 26;

struct tNode {
    tNode* children[ALPHABET_SIZE];
    bool endOfWord;
};

// initiates root tNode to NULL
static tNode* tRoot = NULL;

class Trie {

public:
    
    bool insert(string s);
    bool search(string s);
    
    int getSize();
    
    string getLongestWord();
    string searchLongestWord();
    
    void remove();
    
private:
    
    int size;
    string longestWord;
    
    string searchLongestWord(tNode* n);
    string toLowerCase(string s);
    
    tNode* newNode();
    
    void remove(tNode* n);
    
};

#endif /* TRIE_H */

