#include <bits/stdc++.h>
#include <iostream>
using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

int la,lb,t[2000004],i,lun,nrap;

char a[2000004],b[2000004];

vector<int> sol;

int main()

{

    fin>>(a+1)>>(b+1);

    la=strlen(a+1);

    lb=strlen(b+1);

    t[1]=0;

    for(i=2;i<=la;i++){

        while(lun!=0&&a[lun+1]!=a[i])

            lun=t[lun];

        if(a[lun+1]==a[i])

            lun++;

        t[i]=lun;

    }

    lun=0;

    for(i=1;i<=lb;i++){

        while(lun!=0&&a[lun+1]!=b[i])

            lun=t[lun];

        if(a[lun+1]==b[i])

            lun++;

        if(lun==la){

            nrap++;

            if(nrap<=1000){

                sol.push_back(i-la);

            }

            lun=t[lun];

        }

    }

    fout<<nrap<<"\n";

    for(auto it:sol)

        fout<<it<<" ";

}
