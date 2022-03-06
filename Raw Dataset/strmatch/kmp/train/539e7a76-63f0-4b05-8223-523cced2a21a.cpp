#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

ifstream f ("strmatch.in");

ofstream g ("strmatch.out");

char text[2000005],secv[2000005];

int cnt;

int lps[2000005];

int lungimeText,lungimeSecv;

vector<int>poz;

void formare_lps()

{

    int st = 0,i = 1;



    while(i<lungimeSecv)

    {

        if(secv[i] == secv[st])

        {

            lps[i] = st+1;

            st++;

            i++;

        }

        else

        {

            if(st)

            {

                st = lps[st-1];

            }

            else

                lps[i++] = 0;

        }

    }

}

void verificare_secv_in_text()

{

    int indice_in_secv = 0;

    int i = 0;

    while(i<lungimeText)

    {

        if(text[i] == secv[indice_in_secv])

        {

            indice_in_secv++;

            i++;

        }

        else

        {

            if(indice_in_secv)

                indice_in_secv = lps[indice_in_secv-1];

            else

                i++;

        }

        if(indice_in_secv == lungimeSecv)

        {

            poz.push_back(i-(indice_in_secv));

            indice_in_secv = lps[indice_in_secv-1];

        }

    }

}

int main()

{

    f >> secv>> text;

    lungimeSecv = strlen(secv);

    lungimeText = strlen(text);

    formare_lps();

    verificare_secv_in_text();

    int lungime_v = poz.size();

    g<<lungime_v<< '\n';

    for(int i = 0; i<min(lungime_v,1000); i++)

        g << poz[i]<< " ";

}
