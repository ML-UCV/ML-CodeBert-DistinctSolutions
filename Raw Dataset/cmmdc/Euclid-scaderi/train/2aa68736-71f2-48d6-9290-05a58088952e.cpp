#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    short a,b;
    ifstream in("cmmdc.in");
    in >>a >>b;
    in.close();
    while(a>0 and b>0)
        if(a>b)
            a-=b;
        else
            b-=a;
    ofstream out("cmmdc.out");
    if(a<=0)
        if(b<=1)
            out <<0;
        else
            out <<b;
    else
        if(a<=1)
            out <<0;
        else
            out <<a;
    out.close();
    return 0;
}
