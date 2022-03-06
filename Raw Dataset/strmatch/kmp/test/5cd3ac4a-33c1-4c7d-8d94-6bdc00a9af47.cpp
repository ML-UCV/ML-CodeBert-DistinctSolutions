#include <fstream>
#include <string.h>


using namespace std;



ifstream in("strmatch.in");

ofstream out("strmatch.out");



int aparitii[2000001], k=0;

char A[2000001], B[2000001];



void creareLps(char pat[], int M, int lps[]){



    int len = 0;

    lps[0] = 0;



    int i = 1;

    while (i < M) {

        if (pat[i] == pat[len]) {

            len++;

            lps[i] = len;

            i++;

        }

        else{

            if (len != 0)

                len = lps[len - 1];

            else{

                lps[i] = 0;

                i++;

            }

        }

    }

}



void KMPSearch(char pat[], char txt[])

{

    int M = strlen(pat);

    int N = strlen(txt);



    int lps[M];



    creareLps(pat, M, lps);



    int i = 0;

    int j = 0;

    while (i < N) {

        if (pat[j] == txt[i])

            j++, i++;



        if (j == M) {

            aparitii[++k]=i-j;

            j = lps[j - 1];

        }

        else if (i < N && pat[j] != txt[i]){

            if (j != 0) j = lps[j - 1];

            else i = i + 1;

            }

    }

}



int main()

{

    in.getline(A,2000001);

    in.getline(B,2000001);



    KMPSearch(A,B);



    out<<k<<'\n';

    if(k>1000)k=1000;



    for(int i=1; i<=k; ++i)

        out<<aparitii[i]<<" ";



    in.close();

    out.close();

    return 0;

}
