#include <iostream>
#include <fstream>




using namespace std;

ifstream fi("stramosi.in");

ofstream fo("stramosi.out");



int N, M;



int table[25][250000];



int main()

{

    fi >> N >> M;



    for(int i = 1; i <= N; ++i)

    {

        fi >> table[1][i];

    }



    for(int i = 2; (1 << (i-1)) <= N; ++i)

        for(int j = 1; j <= N; ++j)

            table[i][j] = table[i-1][table[i-1][j]];



    for(int i = 1; i <= M; ++i)

    {

        int node, ancestor;



        fi >> node >> ancestor;

        int currentAncestor = node;

        for(int j = 0; j < 21; ++j)

        {

            if((1 << j) & ancestor)

                currentAncestor = table[j+1][currentAncestor];

        }

        fo << currentAncestor << "\n";

    }

}
