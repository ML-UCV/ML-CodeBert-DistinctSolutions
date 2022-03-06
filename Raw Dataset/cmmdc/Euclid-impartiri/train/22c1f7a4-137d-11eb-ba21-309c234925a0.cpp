#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmmdc.in");

ofstream fout ("cmmdc.out");

unsigned int a,b,r;

int main()

{fin>>a>>b;

while(b)

{r=a%b;

    a=b;

    b=r;

}

if(a!=1)

{fout<<a;



}

else

{

    fout<<0;

}

fin.close();

fout.close();

    return 0;

}
