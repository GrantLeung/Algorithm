#include<iostream>
using namespace std;
class Queue
{
private:
    int head=0,tail=0;
    char* q;
    int capacity;
public:
    Queue(int siz)
    {
        capacity = siz;
        q = new char[capacity];
    }
    void enqueue(char item);
    char dequeue();
    ~Queue()
    {
        delete[] q;
    }
};

void Queue::enqueue(char item)
{
    if((tail+1)%capacity!=head)
    {
        q[tail] = item;
        tail = (tail+1)%capacity;
    }
    else
        return;
}
char Queue::dequeue()
{
    char str;
    if(tail == head)
        return '\0';
    else
    {
        str = q[head];
        head = (head+1)%capacity;
        return str;
    }
}
int main()
{
    Queue qu(5);
    qu.enqueue('A');
    qu.enqueue('B');
    qu.enqueue('C');

    cout<<qu.dequeue();
    cout<<qu.dequeue();
    qu.enqueue('D');
    cout<<qu.dequeue();
    cout<<qu.dequeue();
    qu.enqueue('E');
    qu.enqueue('F');
    qu.enqueue('G');
    cout<<qu.dequeue();
    cout<<qu.dequeue();
    cout<<qu.dequeue();

}
