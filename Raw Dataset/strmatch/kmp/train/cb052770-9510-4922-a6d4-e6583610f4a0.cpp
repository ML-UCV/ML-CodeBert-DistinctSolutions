#include <fstream>
#include <iostream>
#include <cstring>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



int n,m,p[2000010],i,j,l,cnt,sol[1010];

char a[2000010],b[2000010];



int main(){

    fin>>a+1>>b+1;

    n=strlen(a+1);

    m=strlen(b+1);



    l=0;

    for(i=2;i<=n;i++){

        while(l && a[l+1]!=a[i])

            l=p[l];



        if(a[l+1]==a[i])

            l++;



        p[i]=l;

    }



    l=0;

    for(i=1;i<=m;i++){

        while(l && a[l+1]!=b[i])

            l=p[l];



        if(a[l+1]==b[i])

            l++;



        if(l==n){

            cnt++;

            if(cnt<=1000)

                sol[cnt]=i-n;

            l=p[l];

        }

    }



    fout<<cnt<<"\n";

    for(i=1;i<=min(cnt,1000);i++)

        fout<<sol[i]<<" ";



    return 0;

}
