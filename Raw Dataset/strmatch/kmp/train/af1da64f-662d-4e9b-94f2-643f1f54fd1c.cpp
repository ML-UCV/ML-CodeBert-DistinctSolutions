#include <iostream>
#include <fstream>
using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



string txt, pat;



int v[1005];

int lps[2000005];



void computeLPS()

{

    int len = 0, i = 1;



    while(i < pat.size())

    {

        if(pat[i] == pat[len])

        {

            len++;

            lps[i] = len;

            i++;

        }

        else

        {

            if(len)

            {

                len = lps[len-1];

            }

            else

            {

                i++;

            }

        }

    }

}



int nr;



void KMP()

{

    computeLPS();



    int i, j;

    i = j = 0;

    while(i < txt.size())

    {

        if(txt[i] == pat[j])

        {

            i++;

            j++;

        }

        else

        {

            if(j)

            {

                j = lps[j-1];

            }

            else

            {

                i++;

            }

        }

        if(j == pat.size())

        {

            if(nr < 1000)

            {

                v[nr] = i-j;

            }

            nr++;

            j = lps[j-1];

        }

    }





}



int main()

{

    fin>>pat>>txt;



    KMP();



    fout<<nr<<'\n';

    for(int i=0; i<min(1000, nr); i++)

    {

        fout<<v[i]<<' ';

    }



    fin.close();

    fout.close();

    return 0;

}
