#include <fstream>


using namespace std;

ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");

int euclid(int a,int b)

{

    if (b==0)

        return a;

    return euclid(b,a%b);

}

int main()

{

    int a,b,x;

    fin>>a>>b;

    x=euclid(a,b);

    if (x==1)

        fout<<0;

    else

        fout<<x;

    return 0;

}
