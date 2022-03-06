#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <utility>
#include <iomanip>

using namespace std;

typedef long long int LLI;
typedef pair<int,int> PUNCT;

const int NR_PCT = 7;
int DIM;

PUNCT* citire(){

    ifstream fin("cmap.in");

    if(!fin){
        cerr << "Eroare fisier";
        exit(EXIT_FAILURE);
    }

    fin >> DIM;

    PUNCT *vectorX = new PUNCT[DIM + 5];

    if(!vectorX){
        cerr << "Eroare alocare";
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < DIM; i++)
       fin >> vectorX[i].first >> vectorX[i].second;

    fin.close();

    return vectorX;

}

LLI calculDistanta(PUNCT &A, PUNCT &B){

    return (LLI)(A.first - B.first) * (LLI)(A.first - B.first) + (LLI)(A.second - B.second) * (LLI)(A.second - B.second);

}

bool cmpY(PUNCT A, PUNCT B){
    return A.second < B.second;
}

vector <PUNCT> merge(PUNCT *vectorX, int st, int dr){

        int mij = (st + dr) / 2;
        int i = st;
        int j = mij + 1;
        vector <PUNCT> tmpY;

        while(i <= mij && j <= dr){

                if(vectorX[i].second < vectorX[j].second )
                                   tmpY.push_back(vectorX[i++]);
                else
                            tmpY.push_back(vectorX[j++]);
        }

        while ( i <= mij)
                 tmpY.push_back(vectorX[i++]);

        while ( j <= dr )
                 tmpY.push_back(vectorX[j++]);

        int cnt = 0;

        for(int i = st; i <= dr; i++)
                 vectorX[i] = tmpY[cnt++];

        return tmpY;

}

LLI dMinPuncte(PUNCT *vectorX,int st, int dr){

     if( dr - st <= 3){

         if(st == dr)
             return LLONG_MAX;

        if(dr - st == 2){
            LLI dTmp = calculDistanta(vectorX[st],vectorX[dr]);
            merge(vectorX,st,dr);

            return dTmp;

        }

        LLI d_1 = calculDistanta(vectorX[st],vectorX[dr]);
        LLI d_2 = calculDistanta(vectorX[st],vectorX[dr-1]);
        LLI d_3 = calculDistanta(vectorX[st+1],vectorX[dr]);


        if(d_1 < d_2 && d_1 < d_3)
                return d_1;

        if(d_2 < d_1 && d_2 < d_1)
                return d_1;

        return d_3;
    }

    unsigned int indiceMediana = ( st + dr ) / 2;

     if(dr == DIM)
                 dr--;

    LLI dMinSt = dMinPuncte(vectorX,st,indiceMediana);
    LLI dMinDr = dMinPuncte(vectorX,indiceMediana + 1, dr);

    LLI dMin = dMinSt;

    if (dMin > dMinDr)
        dMin = dMinDr;

    vector <PUNCT> tmpY = merge(vectorX,st,dr);

    int lim = tmpY.size();

    for(int i = 0; i < lim; i++){
        for(int j = i + 1; j <= i + NR_PCT && j < lim; j++){

            LLI dTmp = calculDistanta(tmpY[i],tmpY[j]);

            if(dMin > dTmp)
                  dMin = dTmp;

        }
    }

    return dMin;
}

int main(){

    PUNCT *vectorX = citire();
    sort(vectorX, vectorX + DIM);

    ofstream fout("cmap.out");

    fout <<fixed<< setprecision(6) << sqrt(dMinPuncte(vectorX,0, DIM)) << "\n";

    fout.close();

    return 0;
}
