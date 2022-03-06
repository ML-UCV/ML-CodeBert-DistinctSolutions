#include <fstream>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int a,n,x,y;



void euclid_ext(int a,int n,int &x,int &y)

{

    int x0,y0;

    if(n==0)

    {

        x=1;

        y=0;

        return;

    }

    euclid_ext(n,a%n,x0,y0);

    x=y0;

    y=x0-(a/n)*y0;

}

int main()

{

    fin>>a>>n;

    euclid_ext(a,n,x,y);

    while(x<0)

        x+=n;

    fout << x << endl;

    return 0;

}
