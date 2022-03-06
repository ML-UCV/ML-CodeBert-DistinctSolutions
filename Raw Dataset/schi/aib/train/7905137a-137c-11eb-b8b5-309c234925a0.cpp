#include <fstream>
#include <cmath>


using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



const int NMax = 30000;



int AIB[NMax + 5], Sol[NMax + 5], V[NMax + 5], N, T;



void Update(int p, int val)

{

    for(int i = p; i <= N; i += (i & (-i)))

        AIB[i] += val;

}



int Sum(int p)

{

    int Sol = 0;



    for(int i = p; i > 0; i -= (i & (-i)))

        Sol += AIB[i];



    return Sol;

}



int Find(int k)

{

    int Ans = 0;



    for(int i = T; i > 0; i >>= 1)

    {

        if(Ans + i <= N && Sum(Ans + i) < k)

            Ans += i;

    }

    return Ans + 1;

}



int main()

{

    fin >> N;

    T = 1 << ((int)log2(N));



    for(int i = 1; i <= N; i++)

        fin >> V[i], Update(i, 1);



    for(int i = N, p; i >= 1; i--)

    {

        p = Find(V[i]);

        Sol[p] = i;

        Update(p, -1);

    }



    for(int i = 1; i <= N; i++)

        fout << Sol[i] << '\n';



    fin.close();

    fout.close();



    return 0;

}
