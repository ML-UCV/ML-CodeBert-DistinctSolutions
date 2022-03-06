#include <bits/stdc++.h>


using namespace std;



ifstream fin ("strmatch.in");

ofstream fout ("strmatch.out");



char s[4000005];

int kmp[4000005];



void KMP(int n, int l)

{

    int cont = 0;

    kmp[1] = 0;

    for(int i = 2 ;i <= n; ++ i)

    {

        int k = i - 1;

        while(k && s[i] != s[kmp[k] + 1])

            k = kmp[k];

        if(s[i] == s[kmp[k] + 1])

           kmp[i] = kmp[k] + 1;

        else kmp[i] = 0;

        if(kmp[i] == l)

          cont++;

    }

    fout << cont << "\n";

    cont = 0;

    for(int i = 2;i <= n; ++ i)

            if(kmp[i] == l)

            {

                ++cont;

                if(cont <= 1000)

                    fout<<i-2*l-1<<" ";

            }

}

int main()

{

    s[0]='#';

    fin >> (s+1);

    int n, l = strlen(s)-1;

    s[l+1]= '&';

    fin >> (s + l + 2);

    n = strlen(s)-1;

    KMP(n,l);

    return 0;

}
