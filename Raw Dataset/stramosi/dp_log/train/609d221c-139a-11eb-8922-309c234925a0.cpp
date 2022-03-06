#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>


using namespace std;



ifstream in("stramosi.in");

ofstream out("stramosi.out");



const int dim = 250005;



int rmq[20][dim],lg[dim];

vector <int> binar;



int n,m;



int main()

{

    in >> n >> m;

    for (int i=1; i<=n; i++)

    {

        in >> rmq[0][i];

    }

    lg[1] = 0;

    for (int i=2; i<=n; i++)

    {

  lg[i] = lg[i/2] + 1;

    }

    for (int i=1; i<=18; i++)

    {

        for (int j=1; j<=n; j++)

        {

            rmq[i][j] = rmq[i-1][rmq[i-1][j]];

        }

    }

    int p,q;

    int rez = 0,putere,j;

    for (int i=1; i<=m; i++)

    {

        in >> q >> p;

        binar.clear();

        while (p != 0)

        {

            binar.push_back(p%2);

            p /= 2;



        }

        rez = q;

        for (j = 0; j<binar.size(); j++)

        {

            if (binar[j] == 1)

            {

                rez = rmq[j][rez];

            }

        }

        out << rez << "\n";

    }

    return 0;

}
