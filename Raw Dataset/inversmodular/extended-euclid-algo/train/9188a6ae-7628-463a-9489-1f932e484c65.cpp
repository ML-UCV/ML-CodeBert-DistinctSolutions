#include <iostream>
#include <fstream>
using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");





long long A,N,x,y;



void invmod(long long a,long long b,long long &x,long long &y)

{

    if(b==0)

    {

        x=1;

        y=0;

        return;

    }

    long long X,Y;

      invmod(b,a%b,X,Y);

     x=Y;

     y=X-(a/b)*Y;



}





int main()

{



   fin>>A>>N;



   invmod(A,N,x,y);



   while(x<0)

    x+=N;



   fout<<x;





    return 0;

}
