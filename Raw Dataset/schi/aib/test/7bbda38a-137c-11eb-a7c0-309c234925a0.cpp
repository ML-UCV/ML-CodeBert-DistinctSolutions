#include <iostream>
#include <fstream>






using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



const int NMAX = 30005;

int v[NMAX],rasp[NMAX];

int init[NMAX];

int n;



void Update(int poz,int x)

{

    for(int i=poz;i<=n;i+=(i & -i)) v[i]+=x;

}



int Suma(int poz)

{

    int sum=0;

    for(int i=poz;i>=1;i-=(i & -i)) sum+=v[i];

    return sum;

}



int main()

{

    fin >> n;

    for(int i=1;i<=n;i++)

    {

        fin >> init[i];

        Update(i,1);

    }

    int maxim=(n & -n)*2;

    for(int i=n;i>=1;i--)

    {

        int st=0,dr=n,mij;

        int k;

        while(st<=dr)

        {

            mij=(st+dr)/2;

            if(Suma(mij)<init[i])

            {

                st=mij+1;

                k=mij;

            }

            else dr=mij-1;

        }

        k++;

        rasp[k]=i;

        Update(k,-1);

    }

    for(int i=1;i<=n;i++) fout << rasp[i] << '\n';

    return 0;

}
