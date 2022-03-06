#include <fstream>


using namespace std;



int n;

int a[100003], b[100003];



void Citire()

{

    int i;

    ifstream fin("inv.in");

    fin>>n;

    for(i=1;i<=n;++i)

        fin>>a[i];

    fin.close();

}



long long NrInv(int stg, int drp)

{

    if(stg==drp)

        return 0;

    if(drp==stg+1)

    {

        if(a[stg] <= a[drp])

            return 0;

        swap(a[stg],a[drp]);

        return 1;

    }

    int mijl, i, j, indb;

    long long solstg, soldrp, solmijl;

    mijl = (stg+drp)/2;

    solstg = NrInv(stg, mijl);

    soldrp = NrInv(mijl+1, drp);



    solmijl=0;

    i=stg;

    j=mijl+1;

    indb=stg-1;

    while(i<=mijl && j<=drp)

    {

        if(a[i] <= a[j])

        {

            b[++indb] = a[i];

            i++;

        }

        else

        {

            b[++indb] = a[j];

            solmijl += 1LL*(mijl-i+1);

            j++;



        }

    }

    while(i<=mijl)

    {

        b[++indb] = a[i];

        i++;

    }

    while(j<=drp)

    {

        b[++indb] = a[j];

        j++;

    }

    for(i=stg;i<=drp;++i)

        a[i] = b[i];

    return (solstg + solmijl + soldrp)%9917;

}



int main()

{

    Citire();

    ofstream fout("inv.out");

    fout<<NrInv(1,n);



    fout.close();

    return 0;

}
