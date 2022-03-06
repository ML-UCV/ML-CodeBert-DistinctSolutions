#include <iostream>
#include <fstream>
using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

int a,n,d;

pair<int,int> eucl_extins(int x,int y)

{

    if(y==0)

    {

        d=x;

        return {1,0};

    }

    auto p=eucl_extins(y,x%y);

    return {p.second,p.first-(x/y)*p.second};



}

void citire()

{

    f>>a>>n;

    auto p=eucl_extins(a,n);

    if(p.first<0)

        g<<p.first+n;

    else

        g<<p.first;



}

int main()

{

    citire();

    return 0;

}
