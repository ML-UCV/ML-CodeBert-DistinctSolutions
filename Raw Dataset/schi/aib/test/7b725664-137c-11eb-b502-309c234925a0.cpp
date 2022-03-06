#include <fstream>
using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");

const int NMAX=30000;

int sol[NMAX+5], aib[NMAX+5], cit[NMAX+5];

int n;

void update(int val, int poz)

{

    for(;poz<=n;poz=poz+(poz&(-poz)))

        aib[poz]=aib[poz]+val;

}

int query(int poz)

{

    int s=0;

  for(;poz>0;poz=poz-(poz&(-poz)))

     s=aib[poz]+s;

  return s;

}

int cautare_binara(int val)

{

    int st=1, dr=n, mij, valq, sol=n+1;

    while(st<=dr)

    {

        mij=(st+dr)>>1;

        valq=query(mij);

        if(val==valq)

        {

          sol=min(sol, mij);

          dr=mij-1;

          continue;

        }

        if(valq<val)

         st=mij+1;

       else

         dr=mij-1;

    }

    return sol;

}

int main()

{

    int j, i;

    fin>>n;

    for(i=1;i<=n;i++)

        update(1, i);

    for(i=1;i<=n;i++)

        fin>>cit[i];

    for(j=n;j>=1;j--)

    {

        i=cautare_binara(cit[j]);

        update(-1, i);

        sol[i]=j;

    }

    for(i=1;i<=n;i++)

        fout<<sol[i]<<"\n";

    return 0;

}
