#include <iostream>
#include <fstream>


using namespace std;



ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");



int a,b;



int cmmdc(int a, int b)

{

    if(b==0)

        return a;

    else

        return cmmdc(b,a%b);

}



int main()

{

    fin>>a;

    fin>>b;

    int c=cmmdc(a,b);

    if(c==1)

        fout<<0;

    else

        fout<<c;

    return 0;

}
