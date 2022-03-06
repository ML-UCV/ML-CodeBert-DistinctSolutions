#include <fstream>


using namespace std;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



int N, M;

int stramos[19][250005];





int main()

{

    fin >> N >> M;



    for(int i = 1; i <= N; i++)

        fin >> stramos[0][i];



    for(int j = 1; j <= 18; j++)

        for(int i = 1; i <= N; i++)

            stramos[j][i] = stramos[j - 1][stramos[j - 1][i]];



    int q, p;

    for(int i = 1; i <= M; i++)

    {

        fin >> q >> p;



        int masca = 1;

        for(int i = 1; i <= 18; i++)

        {

            if(masca & p)

                q = stramos[i - 1][q];



            masca <<= 1;

        }



        fout << q << '\n';

    }



    return 0;

}
