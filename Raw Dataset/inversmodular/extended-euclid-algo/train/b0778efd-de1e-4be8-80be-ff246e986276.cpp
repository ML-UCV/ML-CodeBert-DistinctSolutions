#include <fstream>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long a,n,x;

void euclid_extins(long long &x,long long &y,long long a,long long b)

{

    if (!b)

    {

        x=1;y=0;

    }

    else

    {

        euclid_extins(x,y,b,a%b);

        int aux=x;

        x=y;

        y=aux-y*(a/b);

    }

}

int main()

{

    fin>>a>>n;

    long long ins=0;

    euclid_extins(x,ins,a,n);

    if(x<=0)

        x=n+x%n;

    fout<<x;





    return 0;

}
