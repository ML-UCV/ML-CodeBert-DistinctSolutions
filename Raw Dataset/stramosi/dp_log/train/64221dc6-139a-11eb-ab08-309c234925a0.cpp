#include <iostream>
#include <fstream>




const char* IN_FILE_NAME = "stramosi.in";

const char* OUT_FILE_NAME = "stramosi.out";



using namespace std;
const int MAX_N = 250000 + 10;

const int MAX_M = 350000 + 10;

const int MAX_LEVELS = 19;



typedef int ancsT[MAX_LEVELS][MAX_N];



ancsT gAncs;



void ReadFirstLevel(ifstream& In, int N)

{

    for (int i = 1; i <= N; ++i)



        In >> gAncs[0][i];

}



void CompleteRemainingLevels(int N)

{

    for (int j = 1; j < MAX_LEVELS; ++j)

        for (int i = 0; i <= N; ++i)



            gAncs[j][i] = gAncs[j - 1][gAncs[j-1][i]];

}



void ResolveQueries(ifstream& In, ofstream& Out, int N, int M)

{

    int q, p;

    for (int m = 0; m < M; ++m)

    {

        In >> q;

        In >> p;



        int anc = q;



        for (int level = 0; (p > 0) && (anc != 0); p >>= 1, ++level)

        {

            if ((p & 1) == 0)

                continue;





            anc = gAncs[level][anc];

        }



        Out << anc << "\n";

    }

}



int main(int argc, char*argv[])

{

    ifstream inF{ IN_FILE_NAME };

    ofstream outF{ OUT_FILE_NAME };



    int n, m;



    inF >> n;

    inF >> m;



    ReadFirstLevel(inF, n);

    CompleteRemainingLevels(n);

    ResolveQueries(inF, outF, n, m);



    return 0;

}
