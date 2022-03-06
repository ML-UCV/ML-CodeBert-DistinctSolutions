#include<iostream>
#include<fstream>




using namespace std;



ifstream fin("cmmdc.in");



ofstream fout("cmmdc.out");



int main ()



{



    int a,b;

    fin>>a>>b;

 if (a >= b && (b <= 30000))

    {

        for (int i = b; i >= 1; i = i-1)

        {

           if (a % i == 0 && b % i == 0 && i != 1)

           {

               fout<<i;

               break ;

           }else if (i == 1)

            {

                fout<<0;

                break ;

            }

        }



    } else if (a < b && (a <= 30000))

    {

        for (int i = a; i >= 1; i = i-1) {

            if (a % i == 0 && b % i == 0 && i != 1)

            {

                fout<<i;

                break ;

            }else if (i == 1)

            {

                fout<<0;

                break ;

            }



        }

    }



    fin.close();



    fout.close();



    return 0;

}
