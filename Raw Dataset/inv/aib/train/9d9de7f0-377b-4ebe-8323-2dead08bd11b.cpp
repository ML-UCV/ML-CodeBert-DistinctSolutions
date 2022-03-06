#include <bits/stdc++.h>
using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");



long long A[100002], Srt[100002];

int N, lg;

int aib[100002];

int i;

int sol;



void update(int X, int val)

{

    for(; X <= lg; X += ((X ^ (X - 1)) & X))

        aib[X] += val;

}



int query(int X)

{

    int ret = 0;

    for(; X >= 1; X -= ((X ^ (X - 1)) & X))

        ret += aib[X];

    return ret;

}



int main()

{

    fin >> N;

    for(i = 1; i <= N; i++)

        fin >> A[i], Srt[i] = A[i];

    sort(Srt + 1, Srt + N + 1);

    lg = 1;

    for(i = 2; i <= N; i++)

        if(Srt[i] != Srt[lg])

            Srt[++lg] = Srt[i];

    for(i = 1; i <= N; i++)

        A[i] = lower_bound(Srt + 1, Srt + lg + 1, A[i]) - Srt;

    for(i = N; i >= 1; i--)

    {

        sol = (sol + query(A[i] - 1)) % 9917;

        update(A[i], 1);

    }

    fout << sol << "\n";

    return 0;

}
