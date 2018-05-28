#include<iostream>
using namespace std;
void merge(int* a,int* aux,int lo,int mid,int hi)
{
    for(int k = lo;k <= hi;k++)
        aux[k] = a[k];
    int i = lo,j = mid + 1;
    for(int k = lo;k <= hi;k++)
    {
        if(i > mid) a[k] = aux[j++];
        else if(j > hi) a[k] = aux[i++];
        else if(aux[j] < aux[i]) a[k] = aux[j++];
        else a[k] = aux[i++];
    }
}
void sort(int* a,int* aux,int lo,int hi)
{
    if(hi <= lo) return;
    int mid = lo + (hi - lo)/2;
    sort(a,aux,lo,mid);
    sort(a,aux,mid+1,hi);
    if(a[mid+1] >= a[mid]) return;
    merge(a,aux,lo,mid,hi);
}
void sort(int* a,int len)
{
    int* aux = new int[len];
    sort(a,aux,0,len-1);
}
int main()
{

    int a[] = {89,6,2,7,8,4,1,952,65,32,698,879,321,564,9,654,645,231,89,21};
    int len = sizeof(a)/sizeof(int);
    int* aux = new int[len];
    sort(a,len);
    for(int i=0;i<len;i++)
        cout<<a[i]<<" ";
}
