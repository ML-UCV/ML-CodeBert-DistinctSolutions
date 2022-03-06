#include <cstdio>
#include <cstring>




char A[50005], B[50005];
int P[26][50005], N, App[26], V[50005], AIB[50005];

void citire()
{
    fgets(A, 50005, stdin);
    fgets(B, 50005, stdin);
    N = strlen(A) - 1;
}

void pre()
{
    for(int i = 0; i < N; ++i)
        P[A[i] - 'a'][++P[A[i] - 'a'][0]] = i+1;
}

void update(int poz)
{
    for(; poz < 50005; poz += poz & -poz)
        ++AIB[poz];
}

int sum(int poz)
{
    int rez = 0;
    for(; poz > 0; poz -= poz & -poz)
        rez += AIB[poz];
    return rez;
}

void solve()
{
    for(int i = 0; i < N; ++i)
    {
        int x = ++App[B[i]-'a'], ord = B[i] - 'a';

        int ind = P[ord][x];
        if(ind == 0)
        {
            printf("-1\n");
            return;
        }
        V[ind] = i+1;
    }
    long long Rez = 0;
    for(int i = 1; i <= N; ++i)
    {
        Rez += sum(50005 -1) - sum(V[i]);
        update(V[i]);
    }
    printf("%lld\n",Rez);
}

int main()
{
    freopen("swap.in","rt",stdin);
    freopen("swap.out","wt",stdout);

    citire();
    pre();
    solve();
}
