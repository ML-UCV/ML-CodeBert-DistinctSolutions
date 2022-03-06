#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;



vector<vector<int> > V(30);

int N, i, ap1[30], ap2[30], ans, W[50010], Aib[50010];

struct data

{

    int pos, val;

}VV[50010];

char S1[50010], S2[50010];



bool cmp(data one, data two)

{

    return one.val > two.val;

}



void Update(int pos)

{

    for(; pos <= N; pos += (pos & (-pos)))

        Aib[pos] ++;

}



int Query(int pos)

{

    int rez = 0;

    for(; pos; pos -= (pos & (-pos)))

        rez += Aib[pos];

    return rez;

}



int main()

{

    freopen("swap.in", "r", stdin);

    freopen("swap.out", "w", stdout);

    fgets(S1, 50001, stdin);

    fgets(S2, 50001, stdin);

    N = strlen(S1);

    for(i = 0; i < N; i++)

    {

        ap1[S1[i] - 'a'] ++;

        ap2[S2[i] - 'a'] ++;

        V[S2[i] - 'a'].push_back(i + 1);

        W[i] = ap1[S1[i] - 'a'];

    }

    for(i = 0; i < 30; i++)

        if(ap1[i] != ap2[i])

        {

            printf("-1\n");

            return 0;

        }

    for(i = 0; i < N; i++)

    {

        VV[i].pos = i + 1;

        VV[i].val = V[S1[i] - 'a'][W[i] - 1];

    }

    sort(VV, VV + N, cmp);

    for(i = 0; i < N; i++)

    {

        ans += Query(VV[i].pos);

        Update(VV[i].pos);

    }

    printf("%i\n", ans);

    return 0;

}
