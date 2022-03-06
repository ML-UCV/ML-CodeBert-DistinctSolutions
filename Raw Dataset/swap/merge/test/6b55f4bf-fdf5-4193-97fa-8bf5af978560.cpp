#include <fstream>
#include <string.h>
using namespace std;

ifstream f("swap.in");

ofstream g("swap.out");

char s[50001],s1[50001];

int n,A[200][50001],viz[50001],v[50001],m,i,a,b,arb[200000],ok;

long long sol;

int query(int nod, int st,int dr){

   int sol=0;

    if(a<=st&&b>=dr)

        return arb[nod];

            int mij=(st+dr)/2;

                if(a<=mij)

                sol=query(2*nod,st,mij);

                if(mij<b)

                   sol+=query(2*nod+1,mij +1,dr);

        return sol;

                }

    void update(int nod , int st,int dr){





if(st==dr){

    arb[nod]++;

        return;

    }

  int mij=(st+dr)/2;

        if(v[i]<=mij)

                update(2*nod,st,mij);

        else

                update(2*nod+1,mij+1,dr);

arb[nod]++;

    }

int main()

{

    f>>s+1;

n=strlen(s+1);

    for(i=1;i<=n;i++){

            A[s[i]][0]++;

        A[s[i]][A[s[i]][0]]=i;

    }

    f>>s1+1;

    m=strlen(s1+1);

    for(i=1;i<=m;i++){

        viz[s1[i]]++;

            v[A[s1[i]][viz[s1[i]]]]=i;}

            for(i='a';i<='z';i++)

            {

                if(viz[i]!=A[i][0]){

                    ok=1;

                    break;

                }

            }

        if(ok==1)

            g<<-1;

        else{

for(i=1;i<=n;i++){



    a=v[i]+1;

    b=n;

    sol+=query(1,1,n);



   update(1,1,n);}

   g<<sol;}

    return 0;

}
