#ifndef HEADER_H
#define HEADER_H
#include "./header.h"
#endif

struct node
{
    int value;
    int counter;
    node *left;
    node *right;

    node(int _val = 0)
    {
        this->value = _val;
        this->left = NULL;
        this->right = NULL;
        counter = 0;
    }
};

class BST
{

    node *root;

public:
    BST()
    {
        root = NULL;
    }

    void insertNode(node *_node)
    {
        if (!this->root)
            root = _node;
        else
        {
            node *temp = root;

            while (1)
            {
                if (_node->value > temp->value)
                    if (temp->right)
                        temp = temp->right;
                    else
                    {
                        temp->right = _node;
                        break;
                    }
                else if (_node->value < temp->value)
                    if (temp->left)
                        temp = temp->left;
                    else
                    {
                        temp->left = _node;
                        break;
                    }
                else if (_node->value == temp->value)
                {
                    temp->counter++;
                    break;
                }
            }
        }
    }
    void search(int val)
    {
        node *temp = root;
        while (temp)
        {
            if (val == temp->value)
            {
                cout << "Node found\n";
                break;
            }
            else if (val > temp->value)
                temp = temp->right;
            else if (val < temp->value)
                temp = temp->left;
        }
        if (!temp)
            cout << "No such value found\n";
    }
    void deleteNode(int val)
    {
        node *temp = root;
        node *prev = temp;
        while (temp)
        {
            if (val == temp->value)
            {

                if (temp->counter > 0)
                    temp->counter--;
                else
                {
                    // incase node is leaf node
                    if (temp->left == NULL && temp->right == NULL)
                    {
                        if (prev->right == temp)
                            prev->right = NULL;
                        else
                            prev->left = NULL;
                        delete temp;
                    }
                    // if node has only one child
                    //  only right child exist
                    else if (temp->left == NULL)
                    {
                        if (prev->right == temp)
                            prev->right = temp->right;

                        else
                            prev->left = temp->right;
                        delete temp;
                    }
                    // only left child exists
                    else if (temp->right == NULL)
                    {
                        if (prev->right == temp)
                            prev->right = temp->left;

                        else
                            prev->left = temp->left;
                        delete temp;
                    }
                    // if node have 2 or more children
                    else
                        deleteByInOrderSuccessor(temp);
                }
                cout << "Deleted successfully...\n";
                return;
            }

            else if (val > temp->value)
            {
                prev = temp;
                temp = temp->right;
            }
            else if (val < temp->value)
            {
                prev = temp;
                temp = temp->left;
            }
        }
        // incase function is not returned during whole traversal
        cout << "No such value found\n";
    }

    void deleteByInOrderSuccessor(node *&root)
    {
        // deleteByInOrderSuccessor search the greatest value node(x) of left side of sub-tree
        // after finding it swap the value with root(node to be deleted) and deletes that node(x)
        node *temp = root->left;
        node *prev = NULL;
        while (temp->right)
        {
            prev = temp;
            temp = temp->right;
        }
        if (prev)
        {
            prev->right = temp->left;
        }
        else
            root->left = temp->left;

        root->value = temp->value;

        delete temp;
    }
    void preOrderTraversal(node *root)
    {
        if (root == NULL)
            return;
        else
        {
            cout << root->value << " ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }

    void inOrderTraversal(node *root)
    {
        if (root == NULL)
            return;
        else
        {
            inOrderTraversal(root->left);
            cout << root->value << " ";
            inOrderTraversal(root->right);
        }
    }
    void postOrderTraversal(node *root)
    {
        if (root == NULL)
            return;
        else
        {
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            cout << root->value << " ";
        }
    }

    node *getRoot()
    {
        return this->root;
    }
    // delete binary tree (post order)
    void deleteTree(node *_root)
    {

        if (_root == NULL)
            return;
        else
        {
            deleteTree(_root->left);
            deleteTree(_root->right);
            delete _root;
        }
    }

    // destructor to delete complete binary tree
    ~BST()
    {
        deleteTree(this->root);
    }
};