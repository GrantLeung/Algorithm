#include<iostream>
using namespace std;
class Node
{
private:
    string item;
    Node* next;


public:
bool isEmpty(Node* s)
{
    if(s == NULL)
        return true;
    else
        return false;
}

void push()
{
    string str;
    cin>>str;
    if(next == NULL){
        Node*p = new Node[1];
        p->item = str;
        next = p;
    }

    else
    {
        Node*p = new Node[1];
        p->item = str;
        p->next = next;
        next = NULL;
        next = p;
    }

}

void pop()
{
    cout<<next->item<<endl;
    Node*p = new Node[1];
    p = next;
    next = next->next;
    delete[] p;
}
};
int main()
{
    Node* p = new Node[50];
    p->push();
    p->push();
    p->push();
    p->push();

    p->pop();
    p->pop();
    p->pop();
    p->push();
    p->pop();
    p->pop();
}
