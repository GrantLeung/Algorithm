#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<queue>
using namespace std;

template <typename Key,typename Value>
class BST
{
private:
    struct Node
    {
        Key key;
        Value val;
        int count;
        Node* left;
        Node* right;
        Node(Key key,Value val)
        {
            this->key = key;
            this->val = val;
        }
    };
    Node* root;
    Node* put(Node* x,Key key,Value val)
    {
        if (x == NULL)
            return new Node(key,val);
        if (key < x->key) x->left = put(x->left,key,val);
        else if (key > x->key) x->right = put(x->right,key,val);
        else
            x->val = val;
            x->count = 1 + size(x->left) + size(x->right);
        return x;
    }
    Node* floor(Node* x,Key key)
    {
        if(x == NULL) return NULL;
        if (key == x->key) return x;
        if (key < x->key) return floor(x->left,key);
        Node* t = floor(x->right,key);
        if(t!= NULL) return t;
        else return x;
    }
    int size(Node* x)
    {
        if(x == NULL) return 0;
        return x->count;
    }
    int rank(Key key,Node* x)
    {
        if(x == NULL) return 0;
        if (key < x->key) return rank(key,x->left);
        else if (key > x->key) return 1+ size(x->left) + rank(key,x->right);
        else return size(x->left);
    }
    void inorder(Node*x,queue<Key> q)
    {
        if(x == NULL) return;
        inorder(x->left,q);
        q.push(x->key);
        inorder(x->right,q);
    }
    Node* deleteMin(Node* x)
    {
        if(x->left == NULL) return x->right;
        x->left = deleteMin(x->left);
        x->count = 1 + size(x->left) + size(x->right);
        return x;
    }
    Node* del(Node* x,Key key)
    {
        if(x == NULL) return NULL;
        if(key < x->key) x->left = del(x->left,key);
        else if(key > x->key) x->right = del(x->right,key);
        else {
            if(x->right == NULL) return x->left;
            if(x->left == NULL) return x->right;

            Node* t = x;
            x = min(t->right);
            x->right = deleteMin(t->right);
            x->left = t->left;
        }
        x->count = size(x->left) + size(x->right) + 1;
        return x;
    }
public:
    void put(Key key,Value val)
    {
        root = put(root,key,val);
    }
    Value get(Key key)
    {
        Node* x = root;
        while(x)
        {
            if (key < x->key) x = x->left;
            else if (key > x->key) x = x->right;
            else return x->val;
        }
        return NULL;
    }
    void deleteMin(Key key)
    {
        root = deleteMin(root);
    }
    bool contains(Key key)
    {
        return get(key) != NULL;
    }
    bool isEmpty()
    {

    }
    int size()
    {
        return size(root);
    }
    Key floor(Key key)
    {
        Node* x = floor(root,key);
        if(x == NULL) return NULL;
        return x.key;
    }
    int rank(Key key)
    {
        return rank(key,root);
    }
    void del(Key key)
    {
        root = del(root,key);
    }
    queue<Key> keys()
    {
        queue<Key> q = new queue<Key>();
        inorder(root,q);
        return q;
    }
};

int main()
{
    BST<string,int> bst;
}
