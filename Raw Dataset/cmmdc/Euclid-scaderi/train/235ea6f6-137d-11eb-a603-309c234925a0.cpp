#include <fstream>




using namespace std;



int a, b;

ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");



int main()

{

    fin>>a>>b;

    while(a!=b)

        if(a>b) a=a-b;

        else b=b-a;

    if(a!=1) fout<<a;

    else fout<<"0";

    fin.close();

    fout.close();

    return 0;

}
