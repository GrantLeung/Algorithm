#include<iostream>

using namespace std;
static bool RED = true;
static bool BLACK = false;
template<typename Key,typename Value>
class RBT
{
private:

    struct Node
    {
        Key key;
        Value val;
        Node* left;
        Node* right;
        bool color;
        Node(Key key,Value val,bool color)
        {
            this->key = key;
            this->val = val;
            this->color = color;
        }
    };
    Node* root;

    Node* rotateLeft(Node* h)
    {
        Node* x = h->right;
        h->right = x->left;
        x->left = h;
        x->color = h->color;
        h->color = RED;
        return x;
    }
    Node* rotateRight(Node* h)
    {
        Node* x = h->left;
        h->left = x->right;
        x->right = h;
        x->color = h->color;
        h->color = RED;
        return x;
    }
    void flipColors(Node* h)
    {
        h->color = RED;
        h->left->color = BLACK;
        h->right->color = BLACK;
    }
    Node* put(Node* h,Key key,Value val)
    {
        if(h == NULL) return new Node(key,val,RED);

        if(key < h->key) h->left = put(h->left,key,val);
        else if (key > h->key) h->right = put(h->right,key,val);
        else if (key == h->key) h->val = val;

        if(isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
        if(isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
        if(isRed(h->left) && isRed(h->right)) flipColors(h);

        return h;

    }
public:
    bool isRed(Node* x)
    {
        if(x == NULL) return false;
        return x->color == RED;
    }
    Value get(Key key)
    {
        Node* x = root;
        while(x != NULL)
        {
            if(key < x->key) x = x->left;
            else if(key > x->key) x = x->right;
            else return x->val;
        }
        return NULL;
    }

    /*void test(Key key)
    {
        Node* x = root;
        cout<<(x->left == NULL);
    }*/
};
int main()
{
    RBT<string,int> rbt;
}
