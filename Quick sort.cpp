#include<iostream>

using namespace std;
void Quick(int *a,int low,int high)
{
    int i = low;
    int j = high;
    int t=a[low];
    if(i<j){
    while(i < j)
    {

        while(i<j&&a[j] >= t)
            j--;
        a[i] = a[j];
        while(i<j&&a[i] <= t)
            i++;
        a[j] = a[i];
    }
    a[i] = t;
    Quick(a,low,i-1);
    Quick(a,i+1,high);}
}
int main()
{
    int a[] = {65,98,31,7,97865,4};
    int n = sizeof(a)/sizeof(int);
    Quick(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
