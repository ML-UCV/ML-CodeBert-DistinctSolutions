#include <iostream>
#include <fstream>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

void cmmdc(int a,int b,int &k,int &l)

{ int kp,lp;

    if(b==0)

       {

           l=0;

           k=1;

           return;

       }

    cmmdc(b,a%b,kp,lp);

    k=lp;

    l=kp-lp*(a/b);



}

int main()

{ int a,x,y,n;

       fin>>a>>n;

       cmmdc(n,a,x,y);

       while(y<0)

        y+=n;

       fout<<y;



    return 0;

}
