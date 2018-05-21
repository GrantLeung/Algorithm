#include<iostream>
//#define capacity 10
using namespace std;
class Stack
{
private:
    char* s;
    int N = 0;
public:
    Stack(int capacity)
    {
        s = new char[capacity];
    }
    bool isEmpty();
    void push(char item);
    char pop();
};

bool Stack::isEmpty()
{
    return N == 0;
}

void Stack::push(char item)
{
    s[N++] = item;
}

char Stack::pop()
{
    return s[--N];
}

int main()
{
    Stack st(10);
    st.push('a');
    cout<<st.pop()<<endl;
}
