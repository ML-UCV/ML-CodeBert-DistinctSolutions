#include <iostream>
#include <fstream>
#include <string.h>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");
char text[2000001], pattern[2000001];

int t, p;

int n, result[2000001];





int lps[2000001];





void calculateLPSArray() {

    int len = 0;

    lps[0] = 0;



    for(int i = 1; i < p; ++i) {

        if(pattern[i] == pattern[len]) lps[i] = ++len;

        else if(len) len = lps[len - 1], --i;

        else lps[i] = 0;

    }

}



void printLPSArray() {

    for (int i=0; i<p; i++) {

        cout<<lps[i]<<" ";

    }

    cout<<endl;

}



void findPatternMatches() {

    calculateLPSArray();



    int j = 0;

    for(int i = 0; i < t;) {

        if(pattern[j] == text[i]) ++i, ++j;

        if(j == p) result[n++] = i - j, j = lps[j - 1];

        else if(i < t && pattern[j] != text[i]) {

            if(j) j = lps[j - 1];

            else ++i;

        }

    }

}



void printResult() {

    fout<<n<<endl;

    if (n > 1000) {

        n = 1000;

    }



    for (int i=0; i<n; i++) {

        fout<<result[i]<<" ";

    }

}



int main()

{

    fin.getline(pattern, 2000001);

    fin.getline(text, 2000001);

    p = strlen(pattern);

    t = strlen(text);



    findPatternMatches();

    printResult();



    return 0;

}
