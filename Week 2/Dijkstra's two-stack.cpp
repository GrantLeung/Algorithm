#include<iostream>
#include<stack>
using namespace std;
int main()
{
    char s[100];
    cin>>s;
    stack<char> ops;
    stack<int> vals;
    int p=0;
    while(s[p]!='\0')
    {
        if(s[p] == '(') ;
        else if(s[p] == '+') ops.push(s[p]);
        else if(s[p] == '*') ops.push(s[p]);
        else if(s[p] == ')')
        {
            char op = ops.top();
            ops.pop();
            if(op == '+')
            {
                int a = vals.top();
                vals.pop();
                int b = vals.top();
                vals.pop();
                vals.push(a+b);
            }
            if(op == '*')
            {
                int c = vals.top();
                vals.pop();
                int d = vals.top();
                vals.pop();
                vals.push(c*d);
            }
        }
        else
            vals.push(s[p]-'0');
            p++;
    }
    cout<<vals.top();
}
