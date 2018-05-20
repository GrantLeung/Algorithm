#include<iostream>
using namespace std;
class Node
{
public:
    string item;
    Node* next;

};

bool isEmpty(Node* s)
{
    if(s == NULL)
        return true;
    else
        return false;
}

void push(Node* s)
{
    string str;
    cin>>str;
    if(s->next == NULL){
        Node*p = new Node[1];
        p->item = str;
        s->next = p;
    }

    else
    {
        Node*p = new Node[1];
        p->item = str;
        p->next = s->next;
        s->next = NULL;
        s->next = p;
    }

}

void pop(Node* s)
{
    cout<<s->next->item<<endl;
    Node*p = new Node[1];
    p = s->next;
    s->next = s->next->next;
    delete[] p;
}

int main()
{
    Node* p = new Node[50];

    cout<<sizeof(p);
}
