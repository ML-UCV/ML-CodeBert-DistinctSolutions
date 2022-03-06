#include <bits/stdc++.h>


using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

char a[2000004],b[2000004];

int la,lb,lun,t[2000004],i,nrsol;

vector<int> sol;

int main()

{

    fin>>(a+1)>>(b+1);

    la=strlen(a+1);

    lb=strlen(b+1);

    lun=0;

    for(i=2; i<=la; i++)

    {

        while(lun!=0&&a[lun+1]!=a[i])

            lun=t[lun];

        if(a[lun+1]==a[i])

            lun++;

        t[i]=lun;

    }

    lun=0;

    for(i=1; i<=lb; i++)

    {

        while(lun!=0&&a[lun+1]!=b[i])

            lun=t[lun];

        if(a[lun+1]==b[i])

            lun++;

        if(lun==la)

        {

            nrsol++;

            if(nrsol<=1000)

                sol.push_back(i-la);

            lun=t[lun];

        }



    }

    fout<<nrsol<<"\n";

    for(auto it:sol)

        fout<<it<<" ";

}
