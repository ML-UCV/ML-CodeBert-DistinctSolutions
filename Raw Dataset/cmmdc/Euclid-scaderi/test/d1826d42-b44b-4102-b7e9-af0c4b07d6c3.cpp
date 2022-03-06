#include <fstream>


using namespace std;

ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");

int s,a,b;

int main()

{

    fin>>a>>b;

    while(a!=b)

    {

        if(a>b)

            a=a-b;

        else

            b=b-a;

    }

    if(a==1)

    {

        fout<<0;

    }

    else

        fout<<a;

    return 0;

}
