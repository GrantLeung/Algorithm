#include<iostream>
using namespace std;
void exch(int* a,int i,int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}
void sort(int* a,int N)
{
    int h = 1;
    while(h < N/3) h = 3*h+1;
    while(h >= 1)
    {
        for(int i=h;i<N;i++)
        {
            for(int j=i;j>=h&&(a[j]<a[j-h]);j-=h)
                exch(a,j,j-h);
        }
        h = h/3;
    }
}
int main()
{
    int a[]={3,6,4,1,2,5,7,9,0,8};
    int N = sizeof(a)/sizeof(int);
    sort(a,N);
    for(int i=0;i<N;i++)
        cout<<a[i]<<" ";
}
