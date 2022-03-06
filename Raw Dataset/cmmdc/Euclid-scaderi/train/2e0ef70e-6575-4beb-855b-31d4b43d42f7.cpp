#include <fstream>


using namespace std;



int main()

{

    ifstream fin("cmmdc.in");

    ofstream fout("cmmdc.out");

    int a,b;

    fin>>a>>b;

    while(a!=b)

    {

        if(a<b)

        b=b-a;

        else a=a-b;

    }

if(a==1)

        fout<<0;

        else fout<<a;

    return 0;

}
