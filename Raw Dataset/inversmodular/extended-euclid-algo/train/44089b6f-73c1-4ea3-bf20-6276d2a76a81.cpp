#include <fstream>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

int T,x,y,A,N;

long long a,b,L,inv,p;

void cmmdc(int a,int b,long long &x,long long &y)

{

    if(!b)

    {

        x=1;

        y=0;

    }

    else

    {

        cmmdc(b,a%b,x,y);

        long long aux=x;

        x=y;

        y=aux-y*(a/b);

    }

}



int main()

{

    fin>>A>>N;

    cmmdc(A,N,inv,p);

    if(inv<=0)

        inv=N+inv%N;

    fout<<inv;

    return 0;

}
