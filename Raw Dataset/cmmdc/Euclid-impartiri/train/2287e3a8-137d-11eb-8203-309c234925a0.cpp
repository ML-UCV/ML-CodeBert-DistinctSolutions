#include <iostream>
#include <fstream>


using namespace std;



ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");



int main()

{

    int a, b, r;

    fin>>a>>b;

    r=a%b;

    while (r!=0)

    {

        a=b;

        b=r;

        r=a%b;

    }

    if (b==1)

        fout<<0;

    else

        fout<<b;

    return 0;

}
