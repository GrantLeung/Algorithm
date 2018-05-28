#include<iostream>
using namespace std;
class Selection
{
public:
    void exch(int* a,int i,int j)
    {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    void sort(int* a,int N)
    {
        for(int i=0;i<N;i++)
        {
            int min = i;
            for(int j=i+1;j<N;j++)
                if(a[j] < a[min])
                    min = j;
            exch(a,i,min);
        }
    }
};
int main()
{
    Selection s;
    int a[] = {3,4,1,2,7,6,5,2,8,9};
    int N = sizeof(a)/sizeof(int);
    s.sort(a,N);
    for(int i=0;i<N;i++)
        cout<<a[i]<<" ";
}
