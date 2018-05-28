#include<iostream>
#define N 12
using namespace std;
class UF
{
    //int N;
public:
    int id[N];
    void init(int id[N])
    {
        for(int i=1;i<=10;i++)
        {
            id[i] = i;
        }
    }
    void Union(int p,int q)
    {
        while(id[q]!=q)
        {
            q=id[q];
        }
        if(id[q]==q)
        id[p]=q;
    }
    bool connected(int p,int q)
    {
        if(id[p]==id[q])
            return true;
        else
            return false;
    }
};
int main()
{
    UF u;
    u.init(u.id);
    u.Union(3,2);
    u.Union(4,3);
    u.Union(5,2);
    int p,q;
    while(cin>>p>>q)
    if(u.connected(p,q))
        cout<<"Connected"<<endl;
        else
            cout<<"None"<<endl;
}
