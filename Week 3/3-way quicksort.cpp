#include<iostream>
#include"sort.h"
using namespace std;

void sort(int* a,int lo,int hi)
{
    if(hi <= lo) return;
    int lt = lo,gt = hi;
    int v = a[lo];
    int i = lo;
    while(i <= gt)
    {
        if(a[i] < v) exch(a,lt++,i++);
        else if(a[i] > v) exch(a,i,gt--);
        else i++;
    }
    sort(a,lo,lt-1);
    sort(a,gt+1,hi);
}

int main()
{
    int a[]={1,2,3,564,2,2,1,987,654,687,687,45};
    int len = sizeof(a)/sizeof(int);
    sort(a,0,len-1);
    for(int i=0;i<len;i++)
    cout<<a[i]<<" ";
}
