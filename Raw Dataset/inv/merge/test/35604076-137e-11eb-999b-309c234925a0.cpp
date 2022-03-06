#include <fstream>


using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");



int a[100005];

long long inv;



void Interclasare(int s,int mij,int d)

{ int b[100005],i,j,k=0;

  i=s; j=mij+1;

  while(i<=mij && j<=d)

      if(a[i]<=a[j]) b[++k]=a[i++];

      else {b[++k]=a[j++]; inv += (mij-i+1)%9917;}

  while(i<=mij) b[++k]=a[i++];

  while(j<=d) b[++k]=a[j++];



  for(i=s,j=1;j<=k;i++,j++)

      a[i]=b[j];

}



void MS(int s,int d)

{ if(s<d)

    { int mij=(s+d)/2;

      MS(s,mij);

      MS(mij+1,d);

      Interclasare(s,mij,d);

    }

}



int main()

{ int i,n,m;

    fin>>n;

    for(i=1;i<=n;i++)

       fin>>a[i];

    MS(1,n);

    fout<< inv%9917;

    return 0;

}
