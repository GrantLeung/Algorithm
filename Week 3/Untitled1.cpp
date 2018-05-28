#include<iostream>
using namespace std;
#define min(x,y) x<y?x:y
int* aux = new int[1001];
void merge(int* a,int lo,int mid,int hi)
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
/*void sort(int* a,int* aux,int lo,int hi)
{
    if(hi <= lo) return;
    int mid = lo + (hi - lo)/2;
    sort(a,aux,lo,mid);
    sort(a,aux,mid+1,hi);
    merge(a,aux,lo,mid,hi);
}*/
void sort(int* a,int N)
{
    int* aux = new int[N];
    //sort(a,aux,0,len-1);
    for(int sz = 1;sz < N;sz = sz+sz)
        for(int lo = 0;lo < N - sz;lo += sz+sz)
        merge(a,lo,lo+sz-1,min(lo+sz+sz-1,N-1));
}
int main()
{

    int a[] = {54,6,49,98,654,698,765,97,65,987,56,4987,58,1};
    int len = sizeof(a)/sizeof(int);
    int* aux = new int[len];
    sort(a,len);
    for(int i=0;i<len;i++)
        cout<<a[i]<<" ";
}
