#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;



vector<vector<int> > V(30);

int N, i, fr1[30], fr2[30], ANS, W[50010], AIB[50010];



struct nr

{

    int P, V;

} VV[50010];



char A[50010], B[50010];



bool cmp(nr a, nr b)

{

    return a.V > b.V;

}



void Update(int P)

{

    for(; P <= N; P += (P & (-P)))

        AIB[P] ++;

}



int Query(int P)

{

    int V = 0;

    for(; P; P -= (P & (-P)))

        V += AIB[P];

    return V;

}



int main()

{

    freopen("swap.in", "r", stdin);

    freopen("swap.out", "w", stdout);

    fgets(A, 50001, stdin);

    fgets(B, 50001, stdin);

    N = strlen(A);



    for(i = 0; i < N; i++)

    {

        fr1[A[i] - 'a'] ++;

        fr2[B[i] - 'a'] ++;

        V[B[i] - 'a'].push_back(i + 1);

        W[i] = fr1[A[i] - 'a'];

    }



    for(i = 0; i < 30; i++)

        if(fr1[i] != fr2[i])

        {

            printf("-1\n");

            return 0;

        }



    for(i = 0; i < N; i++)

    {

        VV[i].P = i + 1;

        VV[i].V = V[A[i] - 'a'][W[i] - 1];

    }



    sort(VV, VV + N, cmp);



    for(i = 0; i < N; i++)

    {

        ANS += Query(VV[i].P);

        Update(VV[i].P);

    }



    printf("%i\n", ANS);

    return 0;

}
