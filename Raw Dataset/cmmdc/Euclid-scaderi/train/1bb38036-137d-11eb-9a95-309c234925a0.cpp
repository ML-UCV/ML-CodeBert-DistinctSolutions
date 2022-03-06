#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");

int main()

{

    int a,b;

    fin>>a>>b;

    while(a>b || b>a)

    {

        if(a>b)a=a-b;

        if(a<b)b=b-a;

    }

    if(a!=1)fout<<a;

    else fout<<0;

    return 0;

}
