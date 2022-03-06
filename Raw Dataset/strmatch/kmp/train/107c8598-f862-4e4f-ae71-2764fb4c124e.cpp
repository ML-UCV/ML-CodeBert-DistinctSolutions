#include <bits/stdc++.h>

using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const int NMAX=2000005;



string S,P;

int lps[NMAX];

vector <int> poz;



void KMP(){



    for(int i=1; i<P.size(); ++i){



        int i2=i;

        for(;i<P.size() and P[i]==P[i-i2]; ++i)

            lps[i]=i-i2+1;

        if(i!=i2) --i;

    }





    int q=0;

    for(int i=0; i<S.size(); ++i)
    {

        for(;q>0 and S[i]!=P[q];)
            q=lps[q-1];

        if(S[i]==P[q]) ++q;

        if(q==P.size()) poz.push_back(i-q+1);

    }

}



int main(){

    fin>>P>>S;
    KMP();


    fout<<poz.size()<<"\n";
    int k=min(int(poz.size()),1000);

    for(int i=0; i<k ; ++i)
        fout<<poz[i]<<" ";

}
