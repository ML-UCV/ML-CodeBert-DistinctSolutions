#include <iostream>
#include <fstream>
using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int a,n,cmmdc;



pair<int, int> euclid_extins(int x, int y)

{

    if(y==0)

    {

        cmmdc=x;

        return {1,0};

    }

    auto p=euclid_extins(y,x%y);

    return {p.second, p.first-(x/y)*p.second};

}

void read()

{

    fin>>a>>n;

    auto p=euclid_extins(a,n);

    fout<<((p.first<0)?(p.first+n):p.first);

}

int main()

{

    read();

    return 0;

}
