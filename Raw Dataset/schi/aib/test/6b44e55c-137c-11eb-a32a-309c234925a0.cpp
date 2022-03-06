#include <bits/stdc++.h>
using namespace std;

ifstream ci("schi.in");

ofstream cou("schi.out");



int aib[30005];

int i,j,v[30005],n,nr,sum,fin[30005];



void Update(int p,int x)

{

    while(p<=n)

    {

        aib[p]+=x;

        p=p+(p&(-p));

    }

}



int Suma(int p)

{

    int s=0;

    while(p>0)

    {

        s=s+aib[p];

        p=p-(p & (-p));

    }

    return s;

}





int main()

{



    ci>>n;

    for(i=1;i<=n;i++){

        ci>>v[i];

    }

    for(i=1;i<=n;i++){

        Update(i,1);

    }

    int st,dr,mij,sol,sm;

    for(i=n;i>=1;i--){

        nr=v[i];

        st=1;

        dr=n;

        sol=1;

        while(st<=dr){

            mij=(st+dr)/2;

            sm=Suma(mij);



            if(sm<v[i]){

                st=mij+1;

            }else{

                sol=mij;

                dr=mij-1;

            }

        }







        Update(sol,-1);

        fin[sol]=i;

    }

    for(i=1;i<=n;i++){

        cou<<fin[i]<<"\n";

    }

    return 0;

}
