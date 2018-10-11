
#include "BinaryTree.h"

// public method, returns pointer to searched value
bNode* BinaryTree::binarySearch(int value)
{
    return binarySearch(value, bRoot);
}

// binary search
bNode* BinaryTree::binarySearch(int value, bNode* n)
{
    // returns NULL in the event the bNode is NULL i.e. the value does not exist 
    if(!n)
        return NULL;
    
    // Searches left for smaller values
    if(value < n->key)
        return binarySearch(value, n->left);
    // Searches right for larger values
    else if(value > n->key)
        return binarySearch(value, n->right);
    
    // returns the current node if it is the searched value
    return n;
}

// creates and returns a new bNode
bNode* BinaryTree::newNode(int value)
{
    bNode* n = new bNode;
    n->key = value;
    n->left = n->right = NULL;
    
    return n;
}

// public method, adds a value to the tree
bool BinaryTree::insert(int value)
{
    // inserts value if root is initialized
    if(bRoot)
        return insert(value, bRoot);
    // initializes the bRoot node
    else
        bRoot = newNode(value);
    
    return true;
}

// private method, inserts the given value into the proper location in the tree
bNode* BinaryTree::insert(int value, bNode* n)
{
    // inserts value into current node if it doesn't yet exist
    if(!n)
        return newNode(value);
    
    // inserts smaller values to the left
    if(value < n->key)
        n->left = insert(value, n->left);
    // inserts larger values to the left
    else if(value > n->key)
        n->right = insert(value, n->right);
    
    // returns n 
    return n;
}

// public method
int BinaryTree::longestBranch()
{
    return longestBranch(bRoot);
}

// searches for longest branch
int BinaryTree::longestBranch(bNode* n)
{
    // returns 0 at a NULL node i.e. the end of a branch
    if(!n)
        return 0;
    
    // recursively compares the longest branch in the left to the right
    return 1 + max(longestBranch(n->left), longestBranch(n->right));
}

// public method, returns largest value
int BinaryTree::searchMax()
{
    return searchMax(bRoot, bRoot->key);
}

// searches tree for largest value
int BinaryTree::searchMax(bNode* n, int maxValue)
{
    // returns the current largest value at the end of a branch
    if(!n)
        return maxValue;
    
    // compares the current bNodes value with the min value returned from the left and right branches
    maxValue = max(n->key, max(searchMin(n->left, maxValue), searchMax(n->right, maxValue)));
    
    // compares the current key to the largest key returned from the left and right branch
    return maxValue;
}

// public method, returns smallest value
int BinaryTree::searchMin()
{
    return searchMin(bRoot, bRoot->key);
}

// searches tree for smallest value
int BinaryTree::searchMin(bNode* n, int minValue)
{
    // returns the current smallest value at the end of a branch
    if(!n)
        return minValue;
    
    // compares the current bNodes value with the min value returned from the left and right branches
    minValue = min(n->key, min(searchMin(n->left, minValue), searchMin(n->right, minValue)));
    
    // returns the smallest value from the left & ri
    return minValue;
}
 
// public method
void BinaryTree::remove()
{
    remove(bRoot);
    return;
}

// removes entire tree from memory
void BinaryTree::remove(bNode* n)
{
    if(n)
    {
        remove(n->left);
        remove(n->right);
        delete n;
    }
    return;
}
