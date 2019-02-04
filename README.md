# Data-Structures
A simple C++ class implementation of various data structures, including user methods to insert, delete, store, and manipulate the desired data structure.   
Data structures included:  
- Binary Search Tree  
  -  A tree data structure where each node has at most 2 children. Values larger than the current node are stored in the right child and smaller values are stored to the left.
  -  Complexity:  
     Access:      O(n)    Θ(log(n))  
     Search:      O(n)    Θ(log(n))  
     Insertion:   O(n)    Θ(log(n))  
     Deletion:    O(n)    Θ(log(n))  
     Space:       O(n)
- Hash Table  
  - Implements an abstract data type storing values as a collection of pairs that maps keys to it's associated values. The keys are generated from the value through a hash funtion giving a unique key representing the index of where the value is stored.
  - Complexity:  
    Access:      N/A     N/A  
    Search:      O(n)    Θ(1)  
    Insertion:   O(n)    Θ(1)  
    Deletion:    O(n)    Θ(1)  
    Space:       O(n)
- Linked List  
  - A simple linear data structure where each value is is appended to the end of the list. Each node stores a value and a pointer to the next value, representing a sequence.
  - Complexity:  
    Access:      O(n)    Θ(n)  
    Search:      O(n)    Θ(n)  
    Insertion:   O(1)    Θ(1)   
    Deletion:    O(1)    Θ(1)  
    Space:       O(n)  
- Trie  
  - A tree data structure storing input words where each node has a maximum of 26 children representing the next character in a string. Prime function is to check whether a specific word exists in the structure, for example a spell checking programming.
  - Complexity:  
    m = length of word  
    Access:      O(m)    Θ(m)  
    Search:      O(m)    Θ(m)  
    Insertion:   O(m)    Θ(m)   
    Deletion:    O(m)    Θ(m)  
    Space:       O(n)
- K-Dimensional Tree  
  - A space partitioning tree data structure storing multi-dimensional values; organizes values in k-dimensional space. Each stored value is in k-dimensions, can be thought of as a hyperplane, which is a division of space into two subspaces. Nodes to the left of the k-dimensional hyperplane are represented by the left subtree of that node and points to the right of the hyperplane are represented by the right subtree.
  - Complexity:  
    Access:      O(n)    Θ(log(n))  
    Search:      O(n)    Θ(log(n))  
    Insertion:   O(n)    Θ(log(n))   
    Deletion:    O(n)    Θ(log(n))  
    Space:       O(n)

