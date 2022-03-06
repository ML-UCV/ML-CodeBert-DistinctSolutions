#include <fstream>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <cmath>


using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



const int NMax = 100000;



const long long oo = 1e18;



int N, K;



pair <long long, long long> P[NMax + 5], V[NMax + 5];



long long Dist(pair <long long, long long> A, pair <long long, long long> B)

{

    return ((A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second));

}



long long DEI(long long L, long long R)

{

    if(L == R)

        return oo;



    if(L == R - 1)

        return Dist(P[L], P[R]);



    long long M = (L + R) / 2, A, B;



    A = DEI(L, M), B = DEI(M + 1, R);



    long long Sol = min(A, B); K = 0;



    for(int i = L; i <= R; i++)

        if(abs(P[i].first - P[M].first) <= Sol)

            V[++K] = {P[i].second, P[i].first};



    sort(V + 1, V + K + 1);



    for(int i = 1; i <= K; i++)

    {

        for(int j = i + 1; j <= i + 8 && j <= K; j++)

            Sol = min(Sol, Dist(V[i], V[j]));

    }

    return Sol;

}



int main()

{

    fin >> N;



    for(int i = 1; i <= N; i++)

        fin >> P[i].first >> P[i].second;



    sort(P + 1, P + N + 1);



    fout << fixed << setprecision(6) << sqrt(DEI(1, N)) << '\n';



    fin.close();

    fout.close();



    return 0;

}
