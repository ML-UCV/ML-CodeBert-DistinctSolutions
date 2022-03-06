#include <iostream>
#include <fstream>
using namespace std;



int main()

{

     int a,b;

    ifstream fin("cmmdc.in");

    ofstream fout("cmmdc.out");

    fin>>a>>b;

    while(a!=b)

    {

        if(a>b) a-=b;

        else b-=a;

    }

    if (a==1) fout<<0;

    else fout<<a;

    fin.close();

    fout.close();

    return 0;

}
