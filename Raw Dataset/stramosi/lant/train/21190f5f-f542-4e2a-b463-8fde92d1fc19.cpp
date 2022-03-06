#include <bits/stdc++.h>


using namespace std;



ifstream in("stramosi.in");

ofstream out("stramosi.out");



const int DIM = 250007;



int p[DIM];



int h[DIM];



bool viz[DIM];



int fr[DIM];



vector < int > d[DIM];



void parinti(int x,int y)

{

    fr[x] = y;



    if(p[x] != 0)

        parinti(p[x],y);



    h[x] = h[p[x]] + 1;

    d[y].push_back(x);

}



int main()

{



    int n, m;



    in >> n >> m;



    for(int i = 1; i <= n; i++)

        {

            in >> p[i];

            viz[p[i]] = true;

        }



    for(int i = 1; i <= n; i++)

    {

        if(viz[i] == false)

            {

                parinti(i,i);



            }

    }





    while(m--)

    {

        int x, y;



        in >> x >> y;



        int pos = h[x];





        pos -= y;



        if(pos <= 0)

            out << 0 <<'\n';

        else

        {

         out << d[fr[x]][pos - 1]<<'\n';

        }





    }







    return 0;

}
