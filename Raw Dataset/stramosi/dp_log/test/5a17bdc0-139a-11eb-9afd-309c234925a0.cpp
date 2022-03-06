#include <bits/stdc++.h>
using namespace std;



const int MAX_N = 25e4 + 1;

const int LOG_MAX_N = 18;



int binary_lifting[LOG_MAX_N][MAX_N], parent[MAX_N], lg[MAX_N], N, M;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");





int main()

{

    fin >> N >> M;



    for(int i = 2; i <= N; ++i)

        lg[i] = lg[i >> 1] + 1;



    for(int i = 1; i <= N; ++i)

        fin >> parent[i];



    for(int i = 1; i <= N; ++i)

        binary_lifting[0][i] = parent[i];



    for(int k = 1; k <= lg[N]; ++k)

        for(int i = 1; i <= N; ++i)

            binary_lifting[k][i] = binary_lifting[k - 1][binary_lifting[k - 1][i]];



    for(int i = 1; i <= M; ++i)

    {

        int q, p;

        fin >> q >> p;



        for(int j = 0; q != 0 && j <= lg[N]; ++j)

        {

            if((1 << j) & p){

                q = binary_lifting[j][q];

            }

        }



        fout << q << '\n';

    }



}
