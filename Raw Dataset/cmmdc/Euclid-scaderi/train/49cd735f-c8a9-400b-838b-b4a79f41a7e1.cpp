#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");

int a,b;



int main()

{

    fin>>a>>b;

    while(a!=b)

    {

        if (a>b)

            a=a-b;

        else

            b=b-a;

    }

    if(a==1)

        fout<<"0";

    else

        fout<<a;

    fin.close();

    fout.close();

    return 0;

}
