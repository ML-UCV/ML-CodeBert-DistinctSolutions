#include <bits/stdc++.h>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const int nmax = 2000005;



string txt, pattern;



int lps[nmax];



void CreateLPS()

{

    int k = 1, len = 0, stop = pattern.length();



    while (k < stop)

    {

        if (pattern[k] == pattern[len])

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

    fin >> pattern >> txt;



    CreateLPS();



    fout << "                                                        \n";



    int i = 0, j = 0, stop = txt.length(), c = 0;



    while (i < stop)

    {

        if (pattern[j] == txt[i])

        {

            i++;

            j++;

        }



        if (j == pattern.length())

        {

            if (c < 1000)

                fout << i - j << ' ';



            c++;



            j = lps[j - 1];

        }

        else if (j < pattern.length() && pattern[j] != txt[i])

        {

            if (j)

                j = lps[j - 1];

            else

                i++;

        }





    }



    fout.close();

    fout.open("strmatch.out", ios::in|ios::out);



    fout << c;



    fin.close();

    fout.close();

    return 0;

}
