#include <fstream>


using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

long long a,M;

void euclid_extins(int &x,int &y,int a,int b)

{

if(!b)

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

{int inv=0,ins;

f>>a>>M;

euclid_extins(inv,ins,a,M);

if(inv<=0) inv=M+inv%M;

g<<inv;

    return 0;

}
