#include <bits/stdc++.h>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const int nmax = 2000005;



int lps[nmax];



int c;



string t, p;



void CreateLPS()

{

    int k = 1, len = 0, s = p.length();



    while (k < s)

    {

        if (p[k] == p[len])

            lps[k++] = ++len;

        else

        {

            if (len)

                len = lps[len - 1];

            else

                k++;

        }

    }

}



int main()

{

    fout << "                                         \n";

    fin >> p >> t;



    CreateLPS();



    int i = 0, j = 0, s = t.length();



    while (i < s)

    {

        if (t[i] == p[j])

        {

            i++;

            j++;

        }

        else

        {

            if (j)

                j = lps[j - 1];

            else

                i++;

        }



        if (j == p.length())

        {

            if (c < 1000)

                fout << i - j << ' ';



            c++;



            j = lps[j - 1];

        }

    }



    fout.close();

    fout.open("strmatch.out", ios::in|ios::out);



    fout << c;



    fin.close();

    fout.close();

    return 0;

}
