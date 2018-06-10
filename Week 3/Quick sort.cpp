#include<iostream>
//#include"sort.h"
using namespace std;
void exch(char a[],int x,int y)
{
    char t;
    t = a[x];
    a[x] = a[y];
    a[y] = t;
}
char partition(char a[],int lo,int hi)
{
    int i=lo,j=hi+1;
    while(true)
    {
        while(a[++i] < a[lo])
            if(i == hi) break;
        while(a[lo] < a[--j])
            if(j == lo) break;

        if(i >= j) break;
        exch(a,i,j);
    }

    exch(a,lo,j);
    return j;
}

void sort(char a[],int lo,int hi)
{
    if(hi <= lo) return;
    int j = partition(a,lo,hi);
    sort(a,lo,j-1);
    sort(a,j+1,hi);
}

int main()
{
    char a[]={'B','C','A','X','R','Y','U','I','C','G'};
    int len = sizeof(a)/sizeof(char);
    sort(a,0,len-1);
    for(int i=0;i<len;i++)
    cout<<a[i]<<" ";
}
