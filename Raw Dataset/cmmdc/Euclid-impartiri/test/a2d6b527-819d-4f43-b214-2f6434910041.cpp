#include <fstream>


using namespace std;

ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");

int a, b, r, ca, cb;

int main()

{

    fin>>a>>b;

    ca=a;

    cb=b;

    while(b!=0)

    {

        r=a%b;

        a=b;

        b=r;

    }

    if(ca==1 || cb==1)

        fout<<1;

    else

    {

        if(a==1)

            fout<<0;

        else

            fout<<a;

    }



    return 0;

}
