#include <iostream>
#include <fstream>


using namespace std;



ifstream f("inv.in");

ofstream g("inv.out");





long a[100001];

int n,nrinv;

long rez;



void Merge(long a[], int st, int dr)

{

    if(st < dr)

    {

        int mij =(st + dr)/2;

        Merge(a,st,mij);

        Merge(a,mij+1,dr);



        int k=0;

        int i=st;

        int j=mij+1;

        int b[100001];

        int nrinv=0;



        while (i <= mij && j<=dr)

            if(a[i]<=a[j])

            {

                b[k]=a[i];

                k++;

                i++;

                rez+=nrinv;

            }

            else

            {

                b[k]=a[j];

                k++;

                j++;

                nrinv++;

            }



        while(i<=mij)

        {

            b[k]=a[i];

            k++;

            i++;

            rez+=nrinv;

        }

        while(j<=dr)

        {

            b[k]=a[j];

            k++;

            j++;

        }

        for(i=st; i<=dr; i++)

        {

            a[i]=b[i-st];

        }

    }

}



int main()

{

    f>>n;

    for(int i=0; i<n; i++)

    {

        f>>a[i];

    }

    Merge(a,0,n-1);

    g<<rez%9917;

}
