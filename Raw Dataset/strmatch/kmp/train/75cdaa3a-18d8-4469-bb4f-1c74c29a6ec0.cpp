#include <iostream>
#include <fstream>
using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



string txt, pat;



int lps[2000005];

int rez[1000];

void computeLps()

{

    int i = 1, len = 0;



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

                lps[i] = 0;

                i++;

            }

        }

    }



}



int nr_rez;

void kmp()

{

    computeLps();

    int n = txt.size(), m = pat.size(), i=0, j=0;

    while(i < n)

    {

        if(txt[i] == pat[j])

        {

            i++;

            j++;

        }

        else

        {

            if(j == 0)

            {

                i++;

            }

            else

            {

                j = lps[j-1];

            }

        }

        if(j == m)

        {

            if(nr_rez < 1000)

            {

                rez[nr_rez] = i-j;

            }

            nr_rez++;

            j = lps[j-1];

        }

    }

}



int main()

{

    fin>>pat>>txt;

    kmp();

    fout<<nr_rez<<'\n';

    for(int i=0; i<min(nr_rez, 1000); i++)

    {

        fout<<rez[i]<<' ';

    }

    fin.close();

    fout.close();

    return 0;

}
