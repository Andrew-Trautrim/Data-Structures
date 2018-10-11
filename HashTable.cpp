
#include "HashTable.h"

// inserts value into the hash table structure
bool HashTable::insert(string value)
{
    string temp = toLowerCase(value);
    unsigned int index = hash(temp);
    
    // inputs value into first link at the index if none already exist
    if(!hTable[index])
    {
        hTable[index] = newNode();
        hTable[index]->value = temp;
        ++size;
        return true;
    }
    
    // inserts value into a list if a value already exists at the same index
    hNode* pTemp = hTable[index];
    
    while(true)
    {
        // inserts value into the first available node
        if(!pTemp)
        {
            pTemp = newNode();
            pTemp->value = temp;
            ++size;
            break;
        }
        
        // returns false if the value already exists
        if(pTemp->value == temp)
        {
            return false;
        }
        
        // moves onto the next node if current one already exists
        pTemp = pTemp->next;
    }
    
    return true;
}

bool HashTable::search(string value)
{
    string temp = toLowerCase(value);
    unsigned int index = hash(temp);
    hNode* pTemp = hTable[index];
    
    while(true)
    {
        // if the node is NULL i.e. the end of the branch
        if(!pTemp)
            return false;
        
        if(temp == string(pTemp->value))
            break;
        
        pTemp = pTemp->next;
    }
    
    return true;
}

// returns an empty node to be inserted into an existing hash table
hNode* HashTable::newNode()
{
    hNode* n = new hNode;
    n->next = NULL;
    
    return n;
}

// returns a lowercase copy of a given string
string HashTable::toLowerCase(string s)
{
    string temp = "";
    
    for(string::size_type i = 0, n = s.size(); i < n; ++i)
        if(isalpha(s[i]))
            temp += tolower(s[i]);
        
    return temp;
}

// Hash function, returns a key used to search data structure for given value
// function found online, author unknown
unsigned int HashTable::hash(string key)
{
    unsigned int temp = 0;
    for(int i = 0; key[i] != '\0'; ++i)
    {
        temp = temp * 31 + key[i];
    }
    
    return temp % HASH_SIZE;
}

//removes the entire data structure from memory
void HashTable::remove()
{
    // iterates over each node list in the table and individually deletes them
    for(int i = 0; i < HASH_SIZE; ++i)
        removeNode(hTable[i]);
    
    return;
}

// deletes each node, and any subsequently attached node
void HashTable::removeNode(hNode* n)
{
    if(n)
    {
        // removes any nodes attached to current one
        removeNode(n->next);
        delete n;
    }
    
    return;
}