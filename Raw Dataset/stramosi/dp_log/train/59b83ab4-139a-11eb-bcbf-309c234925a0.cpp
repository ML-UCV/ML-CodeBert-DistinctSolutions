#include <fstream>




using namespace std;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



int T[20][250005];



int getStramos(int nod, int k){

    for(int pw = 19; pw >= 0; --pw){

        if((1 << pw) <= k){

            k -= (1 << pw);

            nod = T[pw][nod];

        }

    }

    return nod;

}



int main()

{

    int n, k;

    fin >> n >> k;



    for(int i = 1; i <= n; ++i)

        fin >> T[0][i];



    for(int pw = 1; pw <= 19; ++pw)

        for(int i = 1; i <= n; ++i)

            T[pw][i] = T[pw - 1][T[pw - 1][i]];



    for(int i = 1; i <= k; ++i){

        int nod, k;

        fin >> nod >> k;



        fout << getStramos(nod, k) << '\n';

    }

    return 0;

}
