#include <fstream>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

void invmod(long long &invers,long long &ins,int a,int minune)

{

    if(!minune)

        {

            invers=1;

            ins=0;

        }

    else

    {

        invmod(invers,ins,minune,a%minune);

        long long aux=invers;

        invers=ins;

        ins=aux-ins*(a/minune);

    }

}

int main()

{

    long long invers=0,ins;

    int a,minune;

    fin>>a>>minune;

    invmod(invers,ins,a,minune);

    if(invers<=0)

        invers=minune+invers%minune;

    fout<<invers;

    return 0;

}
