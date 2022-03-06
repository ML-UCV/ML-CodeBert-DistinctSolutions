#include <bits/stdc++.h>
using namespace std;



ifstream fin ("schi.in");

ofstream fout ("schi.out");



int N;



int AIB[1 + 30000 + 5];

int A[1 + 30000 + 5];

int Answerts[1 + 30000 + 5];



inline int query (int value)

{

    int answer, sum;

    sum = answer = 0;

    int pow = (1 << 15);

    while (0 <= pow)

    {

        if (pow + answer <= N && sum + AIB[pow + answer] < value)

            answer += pow, sum += AIB[answer];

        if (pow == 0)

            break;

        pow >>= 1;

    }

    return 1 + answer;

}



inline void update (int poz, int value)

{

    while (poz <= N)

        AIB[poz] += value, poz += ((-poz) & poz);

}



int main()

{

    int length = 0;

    fin >> N;

    for (int i = 1; i <= N; ++i)

    {

        int x;

        fin >> x;

        A[++length] = x;

        update (i, 1);

    }

    while (length)

    {

        int poz = query (A[length]);

        Answerts[poz] = length;

        update (poz, -1);

        --length;

    }

    for (int i = 1; i <= N; ++i)

        fout << Answerts[i] << "\n";

    return 0;

}
