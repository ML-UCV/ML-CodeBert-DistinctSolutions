#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>






using namespace std;



ifstream f("strmatch.in");

ofstream g("strmatch.out");



char A[2000005], B[2000005];

int lps[2000005];

vector <int> sol;



void preprocessing(char p[]){

    int i=1, len=0, lsup = strlen(p);

    lps[0] = 0;

    while(i < lsup){

        while(p[i] != p[len] && len > 0)

            len = lps[len-1];

        if(p[i] == p[len]){

            len++;

            lps[i] = len;

        }

        else

            lps[i] = 0;

        i++;

    }

}



void KMP(char pattern[], char s[]){

    int ip=0, is=0, target = strlen(pattern), lsup = strlen(s);

    int contor = 0;

    while(is < lsup)

    {

        while(pattern[ip] != s[is] && ip > 0)

            ip = lps[ip-1];

        if(pattern[ip] == s[is])

            ip++;

        if(ip == target){

            contor++;

            if(contor <= 1000)

                sol.push_back(is-ip+1);

            ip = lps[ip-1];

        }

        is++;

    }

    g<<contor<<"\n";

}



void afisare(vector <int> v){

    int l = v.size();

    for(int i=0; i<l; i++)

        g<<v[i]<<" ";

}



int main()

{

    f>>A>>B;

    preprocessing(A);

    KMP(A,B);

    afisare(sol);

}
