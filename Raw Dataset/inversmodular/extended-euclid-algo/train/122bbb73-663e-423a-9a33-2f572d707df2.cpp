#include <fstream>


using namespace std;

ifstream in ("inversmodular.in");

ofstream out ("inversmodular.out");

void euclid(int a,int b,long long &x,long long &y)

{

    if(b==0)

    {

        y=0;

        x=1;

    }

    else

    {

        euclid(b,a%b,x,y);

        long long d=x;

        x=y;

        y=d-y*(a/b);

    }

}

int main()

{

    int a,n;

    in>>a>>n;

    long long x,y;

    euclid(a,n,x,y);

    if(x<0)

        x=n+x%n;

    out<<x;

    return 0;

}
