#include<iostream>
#include<cstdlib>
#include<ctime>
#define random(a,b) {rand()%(b-a+1)+a}
using namespace std;
void exch(int* a,int i,int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}
void shuffle(int* a,int N)
{
    for(int i=0;i<N;i++)
    {
        srand((unsigned)time(NULL));
        int r = random(0,i);
        exch(a,i,r);
    }
}
int main()
{
    int a[] = {1,2,3,4,5,6};
    int N = sizeof(a)/sizeof(int);
    shuffle(a,N);
    for(int i=0;i<N;i++)
        cout<<a[i]<<" ";
}
