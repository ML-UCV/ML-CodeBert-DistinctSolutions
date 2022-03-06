#include <fstream>
using namespace std;

ifstream fin ("cmmdc.in");

ofstream fout("cmmdc.out");

int main()

{

    int x,y;

    fin>>x>>y;

    while(y)

    {

        int r=x%y;

        x=y;

        y=r;

    }

    if(x!=1)

    fout<<x;

    else

        fout<<0;

}
