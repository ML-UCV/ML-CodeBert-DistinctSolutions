#include<iostream>
#include<fstream>
using namespace std;



ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");



int main()

   {

     int a,b;

   fin >> a >> b;



    while (a!=b)

         {

          if (a>b)

            a-=b;



          else

            b-=a;

     }



  if (a<=1 || b<=1)

            fout << 0;

  else

            fout << a;

   return 0;

}
