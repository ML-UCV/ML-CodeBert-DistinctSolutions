#include <bits/stdc++.h>


using namespace std;



ifstream in("strmatch.in");

ofstream out("strmatch.out");



const int h = 73;

const int mod1 = 100007;

const int mod2 = 100021;



string a;

string b;



vector <int> rez;



int main()

{

   in >> a;

   in >> b;



   int cnt = 0;





   int n = a.size();

   int m = b.size();



   if(n > m)

   {

       out << 0 <<'\n';

       return 0;

   }



   int Sm1 = 0;

   int Sm2 = 0;

   int Sc1 = 0;

   int Sc2 = 0;



   int p1 = 1;

   int p2 = 1;



   for(int i = 0; i < n; i++)

   {

    int nr1 = a[i];

    int nr2 = b[i];



    Sm1 = (Sm1 * h + nr1) % mod1;

    Sm2 = (Sm2 * h + nr1) % mod2;

    Sc1 = (Sc1 * h + nr2) % mod1;

    Sc2 = (Sc2 * h + nr2) % mod2;





    if(i != 0)

        {p1 = (p1 * h) % mod1;

         p2 = (p2 * h) % mod2;

        }



   }



   if(Sc1 == Sm1 && Sc2 == Sm2)

       {

           cnt++;

           rez.push_back(0);

       }





   for(int i = n; i < m; i++)

   {

       int nr1 = b[i - n];

       int nr2 = b[i];





        Sc1 = ((Sc1 - (nr1 * p1) % mod1 + mod1) * h + nr2) % mod1;

  Sc2 = ((Sc2 - (nr1 * p2) % mod2 + mod2) * h + nr2) % mod2;



        if(Sc1 == Sm1 && Sc2 == Sm2)

            {

                cnt++;

                if(cnt <= 1000)

                rez.push_back(i - n + 1);

            }



   }



    out << cnt<<'\n';



    for(int i = 0; i < rez.size(); i++)

        out << rez[i]<<" ";





    return 0;

}
