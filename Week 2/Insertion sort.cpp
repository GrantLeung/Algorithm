#include<iostream>
using namespace std;
class Insertion
{
public:
    void sort(int* a,int N)
    {
        for(int i=0;i<N;i++)
            for(int j=i;j>0;j--)
            if(a[j] < a[j-1])
            exch(a,j,j-1);
            else
                break;
    }
    void exch(int* a,int i,int j)
    {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
};
int main()
{
    Insertion i;
    int a[] = {1,9,7,2,4,3,5,6,8,0};
    int N= sizeof(a)/sizeof(int);
    i.sort(a,N);
    for(int i=0;i<N;i++)
        cout<<a[i]<<" ";
}
