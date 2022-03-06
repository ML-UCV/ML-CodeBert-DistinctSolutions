#include<cstdio>
#include <iostream>
#include <fstream>
using namespace std;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



int n, m;

int v[20][250003];



int main()

{

    int x, y;

    fin>>n>>m;



    for(int i=1; i<=n; i++)

        fin>>v[0][i];



    for(int j=1; j<=17; j++){

        for(int i=1; i<=n; i++)

            v[j][i] = v[j-1][v[j-1][i]];

    }



    for(int i=0; i<m; i++)

    {

        fin>>x>>y;

        for(int j=17; j>=0; j--)

        {

            if((1<<j)<=y)

            {

                y-=(1<<j);

                x = v[j][x];

            }

        }

        fout<<x<<'\n' ;

    }

    return 0;

}
