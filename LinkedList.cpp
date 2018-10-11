
#include "LinkedList.h"

// inserts a new value to the end of the list
bool LinkedList::insert(int value)
{
    // initiates the root if not yet done
    if(!lRoot)
    {
        lRoot = newNode(value);
        lastNode = lRoot;
        return true;
    }
    
    // inserts value into the next available node in the list
    lastNode->next = newNode(value);
    
    // changes the lastNode pointer to the most recent value stored 
    lastNode = lastNode->next;
    
    return true;
}

// searched the list and returns the largest value
int LinkedList::searchMax()
{
    lNode* temp = lRoot;
    int maxValue = lRoot->key;
    
    // iterates over the list
    while(true)
    {
        // breaks the loop at the end of the list
        if(!temp)
            break;
        
        // updates maxValue if needed
        if(temp->key > maxValue)
            maxValue = temp->key;
            
        // moves pointer to the next lNode
        temp = temp->next;
    }
    
    return maxValue;
}

// searched the list and returns the smallest value
int LinkedList::searchMin()
{
    lNode* temp = lRoot;
    int minValue = lRoot->key;
    
    // iterates over the list
    while(true)
    {
        // breaks the loop at the end of the list
        if(!temp)
            break;
        
        // updates maxValue if needed
        if(temp->key < minValue)
            minValue = temp->key;
            
        // moves pointer to the next lNode
        temp = temp->next;
    }
    
    return minValue;
}

// creates and returns a new lNode
lNode* LinkedList::newNode(int value)
{
    lNode* n = new lNode;
    n->key = value;
    n->next = NULL;
    
    return n;
}

// searched the data structure for a given value, limited to a linear search
lNode* LinkedList::search(int value)
{
    // sets temporary pointer to the beginning of the list
    lNode* temp = lRoot;
    
    // iterates over each node in the structure
    while(true)
    {
        if(!temp)
            break;
                
        // return the current node is the value is found
        if(temp->key == value)
            break;
        
        // moves pointer to next node
        temp = temp->next;
    }
    
    // return NULL in the event the value is not found
    return temp;
}

// public method, removes list from memory
void LinkedList::remove()
{
    remove(lRoot);
    return; 
}

// private method, removes the list from memory
void LinkedList::remove(lNode* n)
{
    if(n)
    {
        remove(n->next);
        delete(n);
    }
    return;
}