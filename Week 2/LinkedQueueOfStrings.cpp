#include<iostream>
using namespace std;
struct Node
{
    char item;
    Node* next;
    //int num;
};
class LinkedQueueOfStrings{

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
        first = NULL;
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
    Node* oldlast = last;
    last = new Node[1];
    last->item = item;
    last->next = NULL;
    if(isEmpty())
        first = last;
        else
            oldlast->next = last;
}

char LinkedQueueOfStrings::dequeue()
{
    int item = first->item;
    first = first->next;
    if(isEmpty())
        last = NULL;
    return item;
}

int main()
{
    LinkedQueueOfStrings* q = new LinkedQueueOfStrings[10];
    //q->enqueue('A');
}
