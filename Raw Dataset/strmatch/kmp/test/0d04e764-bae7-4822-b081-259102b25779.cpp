#include <fstream>
#include <string.h>
#include <vector>


using namespace std;



int main()

{

    ifstream f("strmatch.in");

    ofstream g("strmatch.out");

    char A[2000000], ch;

    int N, A_index = -1, B_index = -1, CONTOR = 0;

    vector<int> prefix, SOL;



    f.getline(A, 2000001);

    N = strlen(A);



    prefix.push_back(-1);

    int j = -1;

    for(int i = 1; i < N; i++)

    {

        while(j > -1 && A[j + 1] != A[i])

            j = prefix[j];

        if(A[j + 1] == A[i])

            j++;

        prefix.push_back(j);

    }



    while(f >> ch)

    {

        B_index++;

        while(A_index > -1 && A[A_index + 1] != ch)

            A_index = prefix[A_index];

        if(A[A_index + 1] == ch)

            A_index++;

        if(A_index == N - 1)

        {

            if(CONTOR < 1000)

                SOL.push_back(B_index - N + 1);

            CONTOR++;

            A_index = prefix[A_index];

        }

    }



    g << CONTOR << '\n';

    if(CONTOR > 1000)

        CONTOR = 1000;

    for(int i = 0; i < CONTOR; i++)

        g << SOL[i] << ' ';

    return 0;

}
