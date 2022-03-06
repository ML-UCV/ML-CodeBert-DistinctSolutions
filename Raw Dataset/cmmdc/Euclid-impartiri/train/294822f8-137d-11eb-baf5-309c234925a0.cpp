#include <fstream>
using namespace std;

ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");



int cmmdc (int a,int b)

{

    int r;

    if (a==0&&b==0)

        return -1;

    if (a==0||b==0)

        return max (a,b);

    r=a%b;

    while (r!=0)

    {

        a=b;

        b=r;

        r=a%b;

    }

    return b;

}



int main()

{

    int a,b;

    fin>>a>>b;

    if(cmmdc(a,b)!=1)

        fout<<cmmdc(a,b);

    else

        fout<<0;

    return 0;

}
