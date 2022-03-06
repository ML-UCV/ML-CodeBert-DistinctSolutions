#include <fstream>


using namespace std;

ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");

int d,cmmdc,a,b;

int main()

{

    fin>>a>>b;

    for(d=1;d<=a;d++)if(a%d==0 && b%d==0 and d>cmmdc)cmmdc=d;

    if(cmmdc!=1)fout<<cmmdc;

    else fout<<"0";

    return 0;

}
