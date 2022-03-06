#include <iostream>
#include <fstream>
#include <string.h>


using namespace std;







char text[2000001], pattern[2000001];

int n, lps[2000001], resultext[2000001];

int lenT, lenP;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



void calculateLPSArray() {

    int i=1;

    int j=0;

    lps[0] = 0;

    while (i < lenP) {

        if (pattern[i] == pattern[j]) {

            lps[i] = j+1;

            i++;

            j++;

        }

        else if (j != 0) {

            j=lps[j-1];

        }

        else {

            lps[i] = 0;

            i++;

        }

    }

}



void KMP() {

    int i=0;

    int j=0;



    while (i < lenT) {

        if(text[i] == pattern[j]) {

            i++;

            j++;

        } else if (j != 0) {

            j=lps[j-1];

        } else {

            i++;

        }

        if (j == lenP) {

            n++;

            if (n <= 1000)

                resultext[n] = i-j;

            j = lps[j-1];

        }

    }

}



void printResult() {

    fout<<n<<endl;

    if (n > 1000) {

        n = 1000;

    }

    for (int i=1; i<=n; i++) {

        fout<<resultext[i]<<" ";

    }

}



int main()

{

    fin.getline(pattern, 2000001);

    fin.getline(text, 2000001);

    lenP = strlen(pattern);

    lenT = strlen(text);



    calculateLPSArray();

    KMP();

    printResult();



    return 0;

}
