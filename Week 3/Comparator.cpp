#include<iostream>
using namespace std;
class Date
{
private:
    int month,day,year;
public:
    Date(int m,int d,int y)
    {
        month = m;
        day = d;
        year = y;
    }
    int compareTo(Date that);
};
int Date::compareTo(Date that)
    {
        if(this->year < that.year) return -1;
        if(this->year > that.year) return +1;
        if(this->month < that.month) return -1;
        if(this->month > that.month) return +1;
        if(this->day < that.day) return -1;
        if(this->day > that.day) return +1;
        return 0;
    }
int main()
{
    Date d1(5,30,2018);
    Date d2(5,31,2018);
    cout<<d2.compareTo(d1);
}
