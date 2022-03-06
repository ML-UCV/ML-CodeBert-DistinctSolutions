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

    int i=1, len=0;

    while(i<p)

    {

        if(pattern[i]==pattern[len]){

            lps[i]=len+1;

            len++;

            i++;

        }

        else

        {

            if(len!=0)

                len=lps[len-1];

            else

                lps[i++]=0;

        }

    }

}



void printLPSArray() {

    for (int i=0; i<p; i++) {

        fout<<lps[i]<<" ";

    }

    fout<<endl;

}



void findPatternMatches() {

    calculateLPSArray();

    int i=0, j=0;

    while(i<t)

    {

        if(text[i]==pattern[j])

        {

            i++;

            j++;

        }else{

            if(j)

                j=lps[j-1];

            else

                i++;

        }

        if(j==p){

            result[n++]=i-j;

            j=lps[j-1];

        }

    }

}



void printResult() {

    fout<<n<<"\n";

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
