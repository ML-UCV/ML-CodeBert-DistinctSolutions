#include <iostream>
#include <bits/stdc++.h>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



char sir1[4000005], sir2[2000005];

int p[4000005], lg1, lg2;



void f_pref(char s[], int pref[], int n)

{

    pref[0] = 0;

    for(int i = 1; i < n; i++){

        int j;

        j = i;

        while(j > 0 && s[pref[j - 1]] != s[i]){

            j = pref[j - 1];

        }

        if(j == 0){

            pref[i] = 0;

        }

        else{

            pref[i] = pref[j - 1] + 1;

        }

    }

}



int main()

{

    int i, ct;



    fin >> sir1 >> sir2;

    lg1 = strlen(sir1);

    lg2 = strlen(sir2);

    sir1[lg1] = '#';

    for(i = lg1+1; i <= lg1+lg2; i++){

        sir1[i] = sir2[i-lg1-1];

    }

    f_pref(sir1, p, lg1+lg2+1);

    ct = 0;

    for(i=0; i<=lg1+lg2; i++){

        if(p[i] == lg1){

            ct++;

        }

    }

    fout << ct << '\n';

    ct = 0;

    for(int i=0; i<=lg1+lg2; ++i){

        if(p[i]==lg1 && ct<1000){

            ct++;

            fout<<i-lg1*2<<' ';

        }

    }



    return 0;

}
