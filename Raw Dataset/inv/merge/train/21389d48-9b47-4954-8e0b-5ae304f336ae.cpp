#include <fstream>




using namespace std;

int v[100001],aux[100001],sol;

void intercls(int st,int dr,int mij) {

    int i=st,j=mij+1,k=st-1;

    while (i<=mij || j<=dr)

        if ((v[i]>v[j] && j<=dr) || i>mij)

            aux[++k]=v[j],sol=(sol+mij-i+1)%9917,++j;

        else aux[++k]=v[i],++i;



    for (i=st;i<=dr;++i)

        v[i]=aux[i],aux[i]=0;

}

void msort(int st,int dr) {

  if (st<dr) {

      int mij=(st+dr)/2;

      msort(st,mij);

      msort(mij+1,dr);

      intercls(st,dr,mij);

  }

}

int main()

{ int n,i;

    ifstream f("inv.in");

    ofstream g("inv.out");

    f>>n;

    for (i=1;i<=n;++i)

        f>>v[i];

    msort(1,n);

    g<<sol;

    return 0;

}
