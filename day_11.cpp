//Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, 
//return all strings in the set that have s as a prefix.
//For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

#include<bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct TrieNode{
    struct TrieNode *child[ALPHABET_SIZE];

    bool is_wrd_end;
};
struct TrieNode *getNode(void){
    struct TrieNode *pNode = new TrieNode;
    pNode->is_wrd_end = false;

    for(int i=0;i<ALPHABET_SIZE;i++){
        pNode->child[i] = NULL;
    }
    return pNode;
};

void insert(struct TrieNode *root, const string key){
    struct  TrieNode *pCrawl = root;

    for(int i=0;i<key.length();i++){
        int index = CHAR_TO_INDEX(key[i]);
        if(!pCrawl->child[index])
          pCrawl->child[index] = getNode();

        pCrawl = pCrawl->child[index];  
    }
    pCrawl->is_wrd_end = true;
}
bool search(struct TrieNode *root, const string key)
{
    int length = key.length();
    struct TrieNode *pCrawl = root;
    for (int level = 0; level < length; level++)
    {
        int index = CHAR_TO_INDEX(key[level]);
 
        if (!pCrawl->child[index])
            return false;
 
        pCrawl = pCrawl->child[index];
    }
 
    return (pCrawl != NULL && pCrawl->is_wrd_end);
}

bool isLastNode(struct TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->child[i])
            return 0;
    return 1;
}

void suggestionsRec(struct TrieNode* root, string currPrefix)
{
    if (root->is_wrd_end)
    {
        cout << currPrefix;
        cout << endl;
    }   
    if (isLastNode(root))
        return;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->child[i])
        {
            currPrefix.push_back(97 + i);
            suggestionsRec(root->child[i], currPrefix);
            currPrefix.pop_back();
        }
    }
}

int printAutoSuggestions(TrieNode* root, const string query)
{
    struct TrieNode* pCrawl = root;
    int level;
    int n = query.length();
    for (level = 0; level < n; level++)
    {
        int index = CHAR_TO_INDEX(query[level]);
        if (!pCrawl->child[index])
            return 0;
 
        pCrawl = pCrawl->child[index];
    }
 
    bool isWord = (pCrawl->is_wrd_end == true);
    bool isLast = isLastNode(pCrawl);
 
    if (isWord && isLast)
    {
        cout << query << endl;
        return -1;
    }

    if (!isLast)
    {
        string prefix = query;
        suggestionsRec(pCrawl, prefix);
        return 1;
    }
    return 0;
}

int main(){
    struct TrieNode* root = getNode();
    insert(root , "dog");
    insert(root , "deer");
    insert(root , "deal");

    int comp = printAutoSuggestions(root , "de");
    if (comp == -1)
        cout << "No other strings found with this prefix\n";
 
    else if (comp == 0)
        cout << "No string found with this prefix\n";

    
    return 0;
}