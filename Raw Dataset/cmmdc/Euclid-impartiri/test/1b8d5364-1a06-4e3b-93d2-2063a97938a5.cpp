#include <fstream>
#include <iostream>


using namespace std;



ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");



int main()

{

    int a,b,c;

    fin>>a>>b;

    while(b)

    {

        c=a%b;

        a=b;

        b=c;

    }

    if(a==1) fout<<0;

    else fout<<a;

    return 0;

}
