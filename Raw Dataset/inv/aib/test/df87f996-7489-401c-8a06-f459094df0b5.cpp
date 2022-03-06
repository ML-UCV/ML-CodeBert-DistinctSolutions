#include <bits/stdc++.h>
using namespace std;



ifstream fin ("inv.in");

ofstream fout ("inv.out");



struct Element

{

    int value;

    int index;

    bool operator < (const Element &a)

    {

        return value < a.value || (value == a.value && index < a.index);

    }

};



int N;



Element A[100000 + 5];

int AIB[100000 + 5];



static inline void update (int poz, int value);

static inline int query (int poz);



int main()

{

    fin >> N;

    for (int i = 1; i <= N; ++i)

        fin >> A[i].value, A[i].index = i;

    sort (A + 1, A + N + 1);

    long long sum = 0;

    for (int i = 1; i <= N; ++i)

    {

        sum += 1LL * (query (A[i].index));

        update (A[i].index, 1);

    }

    long long ans = (1LL * N * (N - 1) / 2) - sum;

    fout << ans % 9917;

    return 0;

}



static inline void update (int poz, int value)

{

    while (poz <= N)

        AIB[poz] += value, poz += (poz&(-poz));

}



static inline int query (int poz)

{

    int ans = 0;

    while (poz)

        ans = (ans + AIB[poz]) % 9917, poz -= (poz&(-poz));

    return ans;



}
