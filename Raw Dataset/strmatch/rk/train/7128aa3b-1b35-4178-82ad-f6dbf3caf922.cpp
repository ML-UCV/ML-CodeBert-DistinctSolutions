#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



ifstream fin("strmatch.in");

ofstream gout("strmatch.out");



typedef unsigned long long LL;





const unsigned long long baza = 1010012383;

const unsigned long long m = 1010012359;







LL rasp;



vector<LL>v;



int main()

{

    string a, b;



    fin >> a >> b;

    if( a .size() > b.size() )

        {

            gout <<0;

            return 0;

        }

     LL n = a.size(), i;

     LL vala = 0, valb = 0, put = 1;





     for( i = 0; i < n; ++i )

         {

             vala = ( vala * baza + a[i]) % m;

             put = (put * baza )%m;

         }





     for( i = 0; i < n; ++i )

         valb = ( valb * baza + b[i]) % m;





     if( vala == valb )

    {

        ++rasp;

         v.push_back(0);

    }
     for(i = 1; i <= b.size() - n; ++i )

     {

         valb = ( valb * baza + b[i+n-1] ) % m;







         LL ceva = (put * b[i-1]) % m;

         valb = ( valb - ceva +m) % m;





         if( vala == valb )

             {

                ++rasp;



                if(v.size() < 1000)

                    v.push_back(i);



             }

     }

     gout <<rasp << endl;



    for(int j = 0; j < v.size(); j++)

        {

            gout<<v[j]<<" ";

        }

    return 0;

}
