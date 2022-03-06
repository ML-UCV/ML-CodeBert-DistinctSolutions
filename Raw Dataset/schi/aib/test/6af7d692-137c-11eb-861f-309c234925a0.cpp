#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");



const int nmax=30005;



int n,v[nmax],aib[nmax],sol[nmax] ;



void update(int poz,int val)

{

    for(;poz<=n;poz+= poz & -poz)

        aib[poz]+=val;

}



void read()

{

    fin>>n;



    for(int i=1;i<=n;i++)

    {

        fin>>v[i];



        update(i,1);

    }

}



void solve()

{

    for(int i=n;i>=1;i--)

    {

        int x=v[i],idx=0,p=1<<20;
        for(;p>0;p/=2)

            if(idx+p<=n)

                if(aib[idx+p]<x)

                {

                    idx+=p;

                    x-=aib[idx];

                }







        sol[idx+1]=i;

        update(idx+1,-1);







    }



    for(int i=1;i<=n;i++)

      fout<<sol[i]<<"\n";

}



int main()

{

    read();

    solve();



    return 0;

}
