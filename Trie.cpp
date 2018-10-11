
#include "Trie.h"

// inserts new value into the data structure
bool Trie::insert(string s)
{
    if(!tRoot)
    {
        tRoot = newNode();
        size = 0;
        longestWord = "";
    }
    
    // temporary pointer and string to insert value
    struct tNode* pTemp = tRoot;
    string sTemp = toLowerCase(s);

    // inserts each individual letter into the data structure
    for(int i = 0; sTemp[i] != '\0'; ++i)
    {
        int index = sTemp[i] - 'a';

        // creates new node if none yet exist
        if(!pTemp->children[index])
        {
            // allocates spaces for a new node
            pTemp->children[index] = newNode();
        }

        // moves pointer for the next letter
        pTemp = pTemp->children[index];
    }

    pTemp->endOfWord = true;

    // updates the longest word variable if needed
    if(sTemp.size() > longestWord.size())
        longestWord = sTemp;
    
    // increments the size variable of the structure
    ++size;
    
    return true;
}

// returns true if searched value exists
bool Trie::search(string s)
{
    // temporary pointer and string to check searched value
    tNode* pTemp = tRoot;
    string sTemp = toLowerCase(s);
    
    // checks if each individual letter exists in the structure
    for(int i = 0; s[i] != '\0'; ++i)
    {
        int index = s[i] - 'a';
        if(pTemp->children[index])
            pTemp = pTemp->children[index];
        else
            return false;
    }
    
    // returns true only if there is an end of word identifier
    if(pTemp->endOfWord)
        return true;
    
    return false;
}

// returns the variable representing the amount of words represented by the structure
int Trie::getSize()
{
    return size;
}

// returns the longest word
string Trie::getLongestWord()
{
    return longestWord;
}

// public method, searches the entire data structure and returns the longest word
string Trie::searchLongestWord()
{
    string s = searchLongestWord(tRoot);
    s.pop_back();
    return s;
}

// private method, searches for the longest branch, returns the word represented by that branch
string Trie::searchLongestWord(tNode* n)
{
    // returns an empty string at a NULL node i.e. the end of a branch
    if(!n)
        return "";
    
    // variables to keep track of longest string
    int index = 0;
    string max = "";
    
    // iterates over each possible branch 
    for(int i = 0; i < ALPHABET_SIZE; ++i)
    {
        // gets the longest string of words stemming from current tNode
        string temp = searchLongestWord(n->children[i]);
        
        // updates the longest string of characters if needed
        if(temp.size() > max.size())
        {
            max = temp;
            index = i;
        }
    }
    
    // returns the longest string of tNode values, adding the current tNode value
    return (char)(index + 'a') + max;
}

// returns a lowercase copy of a given string
string Trie::toLowerCase(string s)
{
    string temp = "";
    for(string::size_type i = 0, n = s.size(); i < n; ++i)
    {
        temp += tolower(s[i]);
    }
    
    return temp;
}

// creates new tNode
tNode* Trie::newNode()
{
    tNode* temp = new tNode;
    
    bool endOfWord = false;
    
    // sets children to NULL
    for(int i = 0; i < ALPHABET_SIZE; ++i)
        temp->children[i] = NULL;
    
    // returns newly created tNode
    return temp;
}

// public method, deletes tree from memory
void Trie::remove()
{
    remove(tRoot);
}

// removes the entire data structure from memory
void Trie::remove(tNode* n)
{
    if(n)
        for (int i = 0; i < ALPHABET_SIZE; ++i)
            remove(n->children[i]);
    
    delete(n);
    return;
}
