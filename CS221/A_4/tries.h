#ifndef HEADER_H
#define HEADER_H
#include "./header.h"
#endif

struct trieNode
{
    trieNode *children[ALPHABET_SIZE];
    bool isEnd;

    trieNode()
    {
        // constructor
        isEnd = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = NULL;
    }
};

class trie
{
    trieNode *root;

public:
    trie()
    {
        root = new trieNode;
    }

    void insert(string key)
    {
        trieNode *temp = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            // if the required character node doesn't exist then generate a node there
            if (temp->children[index] == NULL)
                temp->children[index] = new trieNode();

            temp = temp->children[index];
        }
        temp->isEnd = true;
    }
    bool search(string key)
    {
        trieNode *temp = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            // if any where the required character node is NULL then
            // it means that word doesn't exists after this
            // for example : you word :"battle"
            // in data structure b->a->t->NULL (only bat exist not battle)
            if (temp->children[index] == NULL)
                return false;

            temp = temp->children[index];
        }
        // if the isEnd bool is false then the word doesn't exist else it exists
        return temp->isEnd;
    }
};
