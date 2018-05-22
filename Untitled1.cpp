#include<iostream>
using namespace std;

class LinkedQueueOfStrings{
struct Node
{
    char item;
    Node* next;
};
public :
    Node* first ;
    Node* last ;

public:
    bool isEmpty()
    {
        if(first == NULL)
            return true;
        else
            return false;
    }
    LinkedQueueOfStrings()
    {
        first = new Node;
        last = new Node;
    }
    void Init()
    {
        first = new Node[1];
        last = new Node[1];
    }
    void enqueue(char item);
    char dequeue();
    ~LinkedQueueOfStrings()
    {
        delete first;
        delete last;
    }
};
void LinkedQueueOfStrings::enqueue(char item)
{
    Node* oldlast;
    oldlast = last;
    last->item = item;
    last->next = NULL;
    if(first == NULL&&last == NULL) first = last;
    else
        oldlast->next = last;
}

char LinkedQueueOfStrings::dequeue()
{
    char item = first->item;
    first = first->next;
    if(first == NULL&&last == NULL)
        last = NULL;
    return item;
}

int main()
{
    LinkedQueueOfStrings* q = new LinkedQueueOfStrings[10];
    q->Init();
    q->enqueue('A');
    q->enqueue('C');
    cout<<q->first->item;
    cout<<q->last->item;
    q->enqueue('B');
    cout<<q->last->item;
}
