#include <fstream>
#include <cstring>
#include <vector>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const int NMax = 4e6;



char S[NMax + 5], B[NMax + 5];

int L, R, Z[NMax + 5], N, M, Nr;

vector <int> Sol;



int Advance(int j, int i)

{

    while(i < N && S[j] == S[i])

        i++, j++;



    return j;

}



int main()

{

    fin >> S >> B;



    M = strlen(S);

    strcat(S, B);

    N = strlen(S);



    for(int i = 1; i < N; i++)

    {

        if(i > R)

        {

            Z[i] = Advance(0, i);

            L = i, R = i + Z[i] - 1;

        }

        else

        {

            int Ls = 0, Rs = R - L, is = i - L;





            if(is + Z[is] - 1 < Rs)

                Z[i] = Z[is];

            else

            {

                Z[i] = Advance(R - i + 1, R + 1);

                L = i, R = i + Z[i] - 1;

            }

        }

    }



    for(int i = M; i < N; i++)

    {

        if(Z[i] < M) continue;

        Nr++;



        if(Sol.size() < 1000)

            Sol.push_back(i - M);

    }

    fout << Nr << '\n';



    for(auto x : Sol)

        fout << x << " ";



    fin.close();

    fout.close();



    return 0;

}
