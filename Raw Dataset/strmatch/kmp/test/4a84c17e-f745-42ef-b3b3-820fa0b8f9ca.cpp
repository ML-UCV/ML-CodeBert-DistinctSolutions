#include <bits/stdc++.h>






using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



char s[2000005], S[2000005];

int N, M, pi[2000005], k, cnt;



vector < int > Ans;



int main()

{

    fin >> (s + 1);

    N = strlen(s + 1);



    for (int i = 2; i <= N; i++)

    {

        while ((k > 0) && s[k + 1] != s[i])

            k = pi[k];

        if (s[k + 1] == s[i])

            k++;

        pi[i] = k;

    }



    fin >> (S + 1);

    M = strlen(S + 1);



    k = 0;

    for (int i = 1; i <= M; i++)

    {

        while (k > 0 && s[k + 1] != S[i])

            k = pi[k];

        if (s[k + 1] == S[i])

            k++;

        if (k == N)

        {

            cnt++;

            if (cnt <= 1000)

                Ans.push_back(i - N);

        }

    }



    fout << cnt << "\n";

    for (int poz: Ans)

        fout << poz << " ";

    return 0;

}
