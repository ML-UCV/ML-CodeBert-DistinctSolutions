#include <bits/stdc++.h>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const int nmax = 2000005;



string p, t;



int lps[nmax];



void CreateLPS()

{

    int len = 0, k = 1, s = p.length();



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

    fin >> p >> t;



    fout << "                                            \n";



    CreateLPS();



    int i = 0, j = 0, s = t.length(), c = 0;





    while (i < s)

    {

        if (p[j] == t[i])

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

        }

    }



    fout.close();

    fout.open("strmatch.out", ios::in|ios::out);



    fout << c;



    fin.close();

    fout.close();

    return 0;

}
