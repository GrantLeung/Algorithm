void exch(int* a,int x,int y)
{
    int t;
    t = a[x];
    a[x] = a[y];
    a[y] = t;
}
