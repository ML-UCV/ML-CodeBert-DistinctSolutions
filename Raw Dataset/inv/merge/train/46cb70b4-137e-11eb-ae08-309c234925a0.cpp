#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");

int a[100005], b[100005],n,i,inv;

void interclasare(int a[], int aux[], int p, int q, int r, int &inv)

{ int i,j,k,c;

    i=p; j=q+1; k=p; c=0;

    while(i<=q && j<=r)

    {

          if(a[i]<=a[j]) { inv=(inv+c)%9917; aux[k]=a[i]; i++; k++;}

          else {c=j-q; aux[k]=a[j]; j++; k++;}

    }

    while(i<=q){ inv=(inv+c)%9917; aux[k]=a[i]; i++; k++;}

    while(j<=r){aux[k]=a[j]; j++; k++;}

    for(i=p;i<=r;i++){a[i]=aux[i];}

}

void mergesort(int a[], int aux[], int p, int r, int &inv)

{ if(p<r)

    {

        int q=(p+r)/2;

        mergesort(a,aux,p,q,inv);

        mergesort(a,aux,q+1,r,inv);

        interclasare(a,aux,p,q,r,inv);

    }

}



int main()

{

    fin>>n;

    for(i=1;i<=n;i++)fin>>a[i];

    inv=0;

    mergesort(a,b,1,n,inv);

    fout<<inv;

    fout.close();

    fin.close();

    return 0;

}
