#include <fstream>


using namespace std;

void gcd(long long &x,long long &y,int a,int b) {

  if (b==0) x=1,y=0;

  else {

    gcd(x,y,b,a%b);

    long long aux=x;

    x=y;

    y=aux-y*(a/b);

  }

}

int main()

{ long long x=0,y;int a,n;

    ifstream f("inversmodular.in");

    ofstream g("inversmodular.out");

    f>>a>>n;

    gcd(x,y,a,n);

    if (x<=0) x=n+x%n;

    g<<x;

    return 0;

}
