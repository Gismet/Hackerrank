#include <iostream>
#include <vector>
#include <string>

// Number of english alphabet letters
#define NUM_CHARS 26

// Trie node structure
struct TrieNode
{
    int isEnd;       // indicates the end of a word
    int prefixCount; // shows how many words have a certain prefix
    TrieNode *charNodes[NUM_CHARS];
};

// A helper function to create a new Trie node
TrieNode *getNewTrieNode()
{
    TrieNode *newNode = new TrieNode();
    for (int i = 0; i < NUM_CHARS; i++)
        newNode->charNodes[i] == NULL; // set all children of new node to NULL
    newNode->isEnd = 0;
    newNode->prefixCount = 0;
    return newNode;
}

// To add a word to the trie
void add(TrieNode *root, std::string word)
{
    TrieNode *current = root;
    int i = 0;
    while (i < word.length()) // till the end of the word do:
    {
        // if word[i] is in the trie, then increment its prefixCount;
        if (current->charNodes[word[i] - 'a'] != NULL)
        {
            current->charNodes[word[i] - 'a']->prefixCount += 1;
        }
        if (current->charNodes[word[i] - 'a'] == NULL) // if word[i] is not in the trie, add it to the trie and increment its prefixCount;
        {
            current->charNodes[word[i] - 'a'] = getNewTrieNode();
            current->charNodes[word[i] - 'a']->prefixCount += 1;
        }
        current = current->charNodes[word[i] - 'a']; // move to the next letter
        i++;
    }
    current->isEnd = 1; // after adding all characters of the word, make the last character as the end of the word
}

/* Check if there are any words in the trie with the prefix */
int startWith(TrieNode *root, std::string prefix)
{
    if (root == NULL)
    {
        return 0;
    }
    TrieNode *current = root;
    int i = 0;
    while (i < prefix.length())
    {
        if (current->charNodes[prefix[i] - 'a'] == NULL)
        {
            return 0;
        }
        current = current->charNodes[prefix[i] - 'a'];
        i++;
    }
    return 1;
}

/* find how many words there are in the trie with the prefix */
int count_words_with_prefix(TrieNode *root, std::string prefix)
{
    if (root == NULL) // if root is null, trie is empty
    {
        return 0;
    }
    TrieNode *current = root;
    int i = 0;
    while (i < prefix.length()) // check the following for each character of the prefix
    {
        /*Check if the current characters of the prefix is null. If it is, return 0*/
        if (current->charNodes[prefix[i] - 'a'] == NULL)
        {
            return 0;
        }
        // otherwise, move to that character
        current = current->charNodes[prefix[i] - 'a'];
        i++;
    }
    // If we survive the while loop, the we are guaranteed to find the prefix in the trie. return its prefixCount;
    return current->prefixCount;
}

std::vector<int> contacts(std::vector<std::vector<std::string>> queries)
{
    int i = 0;
    std::vector<int> result;
    TrieNode *root = new TrieNode();
    while (i < queries.size())
    {
        if (queries[i][0] == "add")
        {
            add(root, queries[i][1]);
        }
        else
        {
            result.push_back(count_words_with_prefix(root, queries[i][1]));
        }
        i++;
    }
    return result;
}

int main()
{
    TrieNode *root = new TrieNode();
    add(root, "ed");
    add(root, "eddie");
    add(root, "edward");
    add(root, "edwina");
    std::cout << startWith(root, "ed") << std::endl;
    std::cout << count_words_with_prefix(root, "edw");

    return 0;
}
