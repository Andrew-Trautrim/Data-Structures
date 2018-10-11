
#include "k-DimensionalTree.h"

// compares two given strings, checking for equality
bool kDimensionalTree::compare(int arr1[], int arr2[])
{
    // iterates over each dimension
    for(int i = 0; i < K; ++i)
        // returns false if a value in one array doesn't equal the value in the second array in the same position
        if(arr1[i] != arr2[i])
            return false;
    
    // returns true only if all the values in the first array are equal to the second
    return true;
}

// public method, inserts given value into the tree
bool kDimensionalTree::insert(int value[])
{
    kRoot = insert(kRoot, value, 0);
    return true;
}

bool kDimensionalTree::search(int value[])
{
    kNode* temp = search(kRoot, value, 0);
    
    if(temp)
        return true;
    
    return false;
}

// inserts a k-dimensional point into the data structure
kNode* kDimensionalTree::insert(kNode* n, int value[], unsigned int height)
{
    // if current node does not exist
    if(!n)
        return newNode(value);
    
    // keeps track of current depth and the dimension the value is being compared to
    // d = the dimension being compared (x, y, z, ...)
    unsigned int d = height % K;
    
    // returns the current node if value already exists
    if(compare(n->point, value))
        return n;
    
    // values with lesser current dimensional value are stored to the left branch
    if(value[d] < n->point[d])
        n->left = insert(n->left, value, ++height);
    // partitions values with equal and greater values with the same dimension to the right
    else
        n->right = insert(n->right, value, ++height);
    
    return n;
}

kNode* kDimensionalTree::search(kNode* n, int value[], unsigned int height)
{
    // returns NULL at the end of a branch, i.e. the value doesn't exist
    if(!n)
        return NULL;
    
    // keeps track of current depth and the dimension the value is being compared to
    // d = the dimension being compared
    unsigned int d = height % K;
    
    // returns the node if the value is found
    if(compare(n->point, value))
        return n;
    
    // searches left for smaller values
    if(value[d] < n->point[d])
        return search(n->left, value, ++height);
    // searches right for equal and larger values
    else
        return search(n->right, value, ++height);
}

// allocates space and creates a new kNode
kNode* kDimensionalTree::newNode(int value[])
{
    kNode* n = new kNode;
    n->left = n->right = NULL;
    
    for(int i = 0; i < K; ++i)
        n->point[i] = value[i];
    
    return n;
}

// public method, removes tree from memory
void kDimensionalTree::remove()
{
    remove(kRoot);
    return;
}

// removes entire tree from memory
void kDimensionalTree::remove(kNode* n)
{
    if(n)
    {
        remove(n->left);
        remove(n->right);
        delete n;
    }
    return;
}