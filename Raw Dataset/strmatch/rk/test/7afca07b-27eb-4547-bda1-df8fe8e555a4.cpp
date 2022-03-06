#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
const int LMAX = 2000001;
const int MOD1 = 100007;
const int MOD2 = 100021;
const int p = 73;

char a[LMAX], b[LMAX];
bool positions[LMAX];

int main()
{
    FILE *fin, *fout;
    int na,nb,i,hasha1,hasha2,p1,p2,hash1,hash2,nr;
    fin = fopen("strmatch.in","r");
    fout = fopen("strmatch.out","w");
    fscanf(fin,"%s\n%s\n",a,b);

    na = strlen(a), nb = strlen(b);
    hasha1 = hasha2 = 0;
    p1 = p2 = 1;
    for(i=0; i<na; i++){
        hasha1 = (hasha1*p + a[i])%MOD1;
        hasha2 = (hasha2*p + a[i])%MOD2;
        if(i > 0){
            p1 = (p1*p)%MOD1;
            p2 = (p2*p)%MOD2;
        }
    }

    if(na > nb)
        fprintf(fout,"0\n");
    else{
        hash1 = hash2 = 0;
        for(i=0; i<na; i++){
            hash1 = (hash1*p + b[i])%MOD1;
            hash2 = (hash2*p + b[i])%MOD2;
        }
        nr = 0;
        if(hash1 == hasha1 && hash2 == hasha2){
            positions[0] = true;
            nr++;
        }
        for(i=na; i<nb; i++){
            hash1 = ((hash1 - (b[i-na]*p1)%MOD1 + MOD1)*p + b[i])%MOD1;
            hash2 = ((hash2 - (b[i-na]*p2)%MOD2 + MOD2)*p + b[i])%MOD2;
            if(hash1 == hasha1 && hash2 == hasha2){
                positions[i-na+1] = true;
                nr++;
            }
        }
        fprintf(fout,"%d\n",nr);
        nr = 0;
        for(i=0; i<nb && nr<1000; i++)
            if(positions[i] == true){
                fprintf(fout,"%d ",i);
                nr++;
            }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
