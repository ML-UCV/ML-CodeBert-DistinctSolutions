#include <bits/stdc++.h>
using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



string s1, s2;



int prefix[2000005], sol[1005];





int main()

{

    fin >> s1 >> s2;



    int poz = 0;



    int j = 0;



    for(int i = 1; i < s1.size(); i++)

    {

        while(s1[i] != s1[j] && j != 0)

            j = prefix[j - 1];



        if(s1[i] == s1[j])

            j++;



        prefix[i] = j;

    }



    j = 0;



    int k = 0;



    for(int i = 0 ; i < s2.size(); i++)

    {

        while(s2[i] != s1[j] && j != 0)

            j = prefix[j - 1];



        if(s2[i] == s1[j])

        {

            j++;

            if(j == s1.size())

                {

                    k++;



                    if(k <= 1000)

                        sol[k] = i - j + 1;

                    j = prefix[j - 1];

                }

        }

    }

    fout << k << '\n';



    for(int i = 1; i <= min(1000, k); i++)

        fout << sol[i] << " ";



    return 0;

}
