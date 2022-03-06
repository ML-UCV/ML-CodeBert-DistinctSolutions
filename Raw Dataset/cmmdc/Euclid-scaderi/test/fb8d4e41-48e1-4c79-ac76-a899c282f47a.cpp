#include <iostream>
#include <fstream>




using namespace std;



int main()

{

    int a,b,cmmdc;

    ifstream f("cmmdc.in");

    ofstream g("cmmdc.out");

    f>>a;

    f>>b;

    while (a != b)

 {

  if (a > b)

   a = a - b;

  else

   b = b - a;

 }

 if(a==1){

        cmmdc=0;

        g<<cmmdc;

    }else{

        cmmdc=a;

        g<<cmmdc;

    }



    f.close();

    g.close();



    return 0;

}
