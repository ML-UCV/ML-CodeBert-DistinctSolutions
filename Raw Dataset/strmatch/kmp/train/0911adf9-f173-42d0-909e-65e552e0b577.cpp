#include <bits/stdc++.h>
#include <fstream>


using namespace std;



ifstream in("strmatch.in");

ofstream out("strmatch.out");





vector<int>rez;



int n , m;



int pi[2000005];



char w[2000005];

char s[2000005];



int cazan = 0;



void generate_pi()

{

    pi[1] = 0;

    int k = 0;

    for(int i = 2; i <= n; ++i)

    {

        while(k && w[k + 1]!=w[i])

            k = pi[k];

        if(w[k + 1] == w[i])

            k++;

        pi[i] = k;

    }

}



void kmp()

{

    int k = 0;

    for(int i = 1; i <= m; ++i)

    {

        while(k && w[k + 1]!=s[i])

            k = pi[k];

        if(w[k + 1] == s[i])

            k++;

        if(k == n)

            {cazan++;

            if(cazan <= 1000)

            rez.push_back(i - n + 1);}



    }

}



int main()

{

    in >> (w + 1);

    in >> (s + 1);

    n = strlen(w + 1);

    m = strlen(s + 1);

    generate_pi();

    kmp();

    out << cazan << '\n';

    for(auto &i : rez)

        out << i - 1 << " ";

    return 0;

}
