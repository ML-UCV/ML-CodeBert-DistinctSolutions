#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



int n, m, k, sol[2000050], d[2000050];

char patern[2000050], sir[2000050];
void lps(){

    int l=0;

    d[0]=0;

    int i=1;

    while(i<m){

        if(patern[i]==patern[l]){

            l++;

            d[i]=l;

            i++;

        }else{

            if(l!=0){

                l=d[l-1];

            }else{

                d[i]=0;

                i++;

            }

        }

    }

}







void kmp(){





    int i=0;

    int j=0;

    lps();

    while(i<n){

        if(sir[i]==patern[j]){

            i++;

            j++;

        }

        if(j==m){



            k++;

            sol[k]=i-j;

            j=d[j-1];

        }else if(i<n && sir[i]!=patern[j]){

            if(j){

                j=d[j-1];

            }else{

                i++;

            }

        }

    }

}







int main(){

    fin>>patern;

    fin>>sir;

    m=strlen(patern);

    n=strlen(sir);

    kmp();

    fout<<k<<"\n";

    for(int i=1; i<=min(1000, k); i++){

        fout<<sol[i]<<" ";

    }

}
