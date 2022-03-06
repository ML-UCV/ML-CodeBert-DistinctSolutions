#include <fstream>




using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");



int a[100001],n;

int inv;



void InterCls(int v[],int l,int m, int r)

{ int i,j,k=0;

  int aux[100001];

  i=l;

  j=m+1;

  while(i<=m && j<=r)

        if(v[i]<=v[j])

            aux[k++]=v[i++];

        else

           {aux[k++]=v[j++];

            inv+=(m-i+1);

            inv%=9917;

           }

  while(i<=m)

       aux[k++]=v[i++];

  while(j<=r)

       aux[k++]=v[j++];

  int ct=0;

  for(i=l; i<=r; i++)

      v[i]=aux[ct++];

}



void MergeSort(int v[],int l,int r)

{ if(l<r)

    {int m=(l+r)/2;

     MergeSort(v,l,m);

     MergeSort(v,m+1,r);

     InterCls(v,l,m,r);

    }

}



int main()

{ fin>>n;

  int i;

  for(i=1; i<=n; i++)

       fin>>a[i];

  MergeSort(a,1,n);

  fout<<inv%9917;

    return 0;

}
