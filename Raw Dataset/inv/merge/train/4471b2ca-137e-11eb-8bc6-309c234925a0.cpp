#include <iostream>
#include <fstream>


using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");



const int NMAX = 100005;

const int MOD = 9917;

int a[NMAX];

int b[NMAX];

int rasp;



void msort(int st,int dr)

{

    if(st==dr) return;

    int mij=(st+dr)/2;

    msort(st,mij);

    msort(mij+1,dr);

    int i=st;

    int j=mij+1;

    int k=0;

    while(i<=mij and j<=dr)

    {

        if(a[i]>a[j])

        {

            rasp+=mij-i+1;

            rasp%=MOD;

            b[++k]=a[j];

            j++;

        }

        else

        {

            b[++k]=a[i];

            i++;

        }

    }

    while(i<=mij)

    {

        b[++k]=a[i];

        i++;

    }

    while(j<=dr)

    {

        b[++k]=a[j];

        j++;

    }

    k=1;

    for(int i=st;i<=dr;i++)

    {

        a[i]=b[k];

        k++;

    }

}



int main()

{

    int n;

    fin >> n;

    for(int i=1;i<=n;i++)

    {

        fin >> a[i];

    }

    msort(1,n);

    fout << rasp << '\n';

    return 0;

}
