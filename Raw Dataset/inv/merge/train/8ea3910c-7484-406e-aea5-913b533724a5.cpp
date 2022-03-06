#include <fstream>
using namespace std;

ifstream f("inv.in");

ofstream g("inv.out");

int i,a[100005],aux[100005],n,k;

void interclasare(int a[],int aux[],int p,int q,int r,int &inv)

{

    int i,j,k,c;

    i=p;

    j=q+1;

    k=p;

    c=0;

    while(i<=q&&j<=r)

    {

        if(a[i]<=a[j])

        {

            aux[k]=a[i];

            inv=(inv+c)%9917;

            i++;

            k++;

        }

        else

        {

            aux[k]=a[j];

            c=j-q;

            j++;

            k++;

        }

    }

    while(i<=q)

    {

        aux[k]=a[i];

        inv=(inv+c)%9917;

        i++;

        k++;

    }

    while(j<=r)

    {

        aux[k]=a[j];

        j++;

        k++;

    }

   for(i=p;i<=r;i++){a[i]=aux[i];}

}

void mgsort(int a[],int aux[],int p,int r,int &inv)

{

   int q;

   if(p<r)

   {

       q=(p+r)/2;

       mgsort(a,aux,p,q,inv);

       mgsort(a,aux,q+1,r,inv);

       interclasare(a,aux,p,q,r,inv);

   }

}

int main()

{

 f>>n;

 for(i=1;i<=n;i++)

    f>>a[i];

 mgsort(a,aux,1,n,k);

 g<<k;

 return 0;

}
