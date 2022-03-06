#include<fstream>
#include<vector>
#include<cmath>
using namespace std;



ifstream in("inversmodular.in");

ofstream out("inversmodular.out");



const int NMax = 1e5;

vector <int> PrimeList;



int A, N, Nprim, Prime[NMax], Div[NMax], NrDivs;

long long Sol = 1;



int LogPow(int X, int P,int MOD) {

    long long ans = 1;

    while (P) {

        if (P % 2 == 1)

            ans = (1LL * ans * X) % MOD;

        X = (1LL * X * X) % MOD;

        P /= 2;

    }

    return ans;

}



void Sieve()

{

    for(int i = 2; i <= NMax; i++)

        if(Prime[i] == 0)

        {

            PrimeList.push_back(i);



            for(int j = 2 * i; j <= NMax; j += i)

                Prime[j] = 1;

        }

}



void Decompose()

{

    Nprim = N;

    for(auto x : PrimeList)

    {

        if(x * x > N) break;

        if(N % x) continue;



        while(N % x == 0)

            N /= x;



        Div[++NrDivs] = x;

    }

    if(N > 1) Div[++NrDivs] = N;

}



void Solve() {

    Sol = Nprim;

    for (int i = 1; i <= NrDivs; i++) {

        Sol *= (Div[i] - 1);

        Sol /= Div[i];

    }

}



int main() {

    in >> A >> N;

    Sieve();

    Decompose();

    Solve();

    out << LogPow(A,Sol-1,Nprim);

}
