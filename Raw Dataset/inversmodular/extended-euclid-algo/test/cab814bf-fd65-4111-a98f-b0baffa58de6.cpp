#include <fstream>


using namespace std;



int eucl(int a,int b,int c,int &x, int &y)

{

    int q[100],x0,y0,r,pas=0;

    while (b)

    {

        q[++pas]=a/b;

        r=a%b;

        a=b;

        b=r;

    }

        if (c%a) {x=y=0;return 0;}

        x=x0=c/a;

        y=y0=0;

        while(pas)

        {

            x=y0;

            y=x0-q[pas--]*y0;

            x0=x;

            y0=y;

        }

        return 1;

}





int main()

{

   ifstream f("inversmodular.in");

   ofstream fout("inversmodular.out");

   int a,b,x,y;

        f>>a>>b;

        eucl(a,b,1,x,y);

        x=((long long)b+x%b)%b;

        fout<<x;

    return 0;

}
