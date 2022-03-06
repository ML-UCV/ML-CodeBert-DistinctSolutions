#include <iostream>
#include <fstream>
#include <cstring>




using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



char s[2000001], p[2000001];



int sol[1001], lps[2000001], cnt, ccnt;



void computeLPSArray(char* pat, int M, int* lps);



void KMPSearch(char* pat, char* txt)

{

    int M = strlen(pat);

    int N = strlen(txt);
    computeLPSArray(pat, M, lps);



    int i = 0;

    int j = 0;

    while (i < N) {

        if (pat[j] == txt[i]) {

            j++;

            i++;

        }



        if (j == M) {





            if (cnt <= 999) {

                cnt++;

                ccnt++;

                sol[cnt] = i - j;

            }

            else

            {

                ccnt++;

            }

            j = lps[j - 1];

        }





        else if (i < N && pat[j] != txt[i]) {





            if (j != 0)

                j = lps[j - 1];

            else

                i = i + 1;

        }

    }

}





void computeLPSArray(char* pat, int M, int* lps)

{



    int len = 0;



    lps[0] = 0;





    int i = 1;

    while (i < M) {

        if (pat[i] == pat[len]) {

            len++;

            lps[i] = len;

            i++;

        }

        else

        {







            if (len != 0) {

                len = lps[len - 1];







            }

            else

            {

                lps[i] = 0;

                i++;

            }

        }

    }

}



int main()

{

    fin.getline(p, 2000001);

    fin.getline(s, 2000001);

    KMPSearch(p, s);

    fout << ccnt << '\n';

    for (int i = 1; i <= cnt; i++) {

        fout << sol[i] << ' ';

    }

}
