#include <cstdio>
#include <vector>


using namespace std;



const int maxN = 1 << 16;



vector<int> A[26], B[26];



int N, Perm[maxN], Aib[maxN];

char a[maxN], b[maxN];



int Sol;



inline int lsb(int x){

    return (x ^ (x - 1)) & x;

}



void Update(int poz, int val){

    while (poz <= N){

        Aib[poz] += val;

        poz += lsb(poz);

    }

}



int Query(int poz){

    int S = 0;

    while (poz){

        S += Aib[poz];

        poz -= lsb(poz);

    }



    return S;

}



int main(){

    int i, j;



    freopen("swap.in", "r", stdin);

    freopen("swap.out", "w", stdout);



    fgets(a, 50001, stdin);

    fgets(b, 50001, stdin);



    for (N = 0; a[N] != 0; ++N);



    for (i = 0; i < N; ++i) A[a[i] - 'a'].push_back(i);



    for (i = 0; i < N; ++i) B[b[i] - 'a'].push_back(i);



    for (i = 0; i <= 25; ++i){

        if (A[i].size() != B[i].size()){

            printf("-1\n");

            return 0;

        }

        for (j = 0; j < A[i].size(); ++j) Perm[A[i][j] + 1] = B[i][j] + 1;

    }



    Update(Perm[1], 1);

    for (i = 2; i <= N; ++i){

        Sol += Query(N) - Query(Perm[i]);

        Update(Perm[i], 1);

    }



    printf("%d\n", Sol);



}
