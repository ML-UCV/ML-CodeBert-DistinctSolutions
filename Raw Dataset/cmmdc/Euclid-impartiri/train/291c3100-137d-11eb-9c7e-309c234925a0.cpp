#include <iostream>
#include <fstream>




using namespace std;



long long int a,b,r,aux;



int main()



{



    ifstream fin("cmmdc.in");



    ofstream fout("cmmdc.out");



    fin>>a;



    fin>>b;



    if (b>a)



    {



        aux=b;



        b=a;



        a=aux;



    }



    r=a%b;



    while (r)



    {



        a=b;



        b=r;



        r=a%b;



    }

 if (b==1)

        fout<<"0";

    else

    fout<<b;



    return 0;



}
